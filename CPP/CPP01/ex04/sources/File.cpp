#include "File.hpp"

File::File(std::string filename): openFile(filename), writeFile(filename + ".replace", std::ofstream::trunc)
{
    if (!this->openFile.is_open()) {
        this->openFileClose();
        throw std::runtime_error("Input file is not open!!");
    }
    if (!this->writeFile.is_open()) {
        this->openFileClose();
        this->writeFileClose();
        throw std::runtime_error("Output file is not open!!");
    }
}

File::~File()
{
    this->openFileClose();
    this->writeFileClose();
}

void File::replaceLine(std::string &line, std::string origin, std::string replace)
{
    std::string::size_type  start;
    std::string::size_type  idx = 0;

    while ((start = line.find(origin, idx)) != std::string::npos) {
        line.erase(start, origin.length());
        line.insert(start, replace);
        idx = start + replace.length();
    }
}

void File::openFileClose() { this->openFile.close(); }

void File::writeFileClose() { this->writeFile.close(); }

void File::replaceFile(std::string origin, std::string replace)
{
    std::string buffer;

    while (true) {
        std::getline(this->openFile, buffer);
        this->replaceLine(buffer, origin, replace);
        writeFile << buffer;
        if (openFile.eof())
            break ;
        if (!origin.compare("\n"))
            writeFile << replace;
        else
            writeFile << "\n";
    }
}
