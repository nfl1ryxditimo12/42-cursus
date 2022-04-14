#include "File.hpp"

File::File(std::string filename): openFile(filename), writeFile(filename + ".replace", std::ofstream::trunc)
{
    if (!this->openFile.is_open())
        throw std::runtime_error("Input file is not open!!");
    if (!this->writeFile.is_open())
        throw std::runtime_error("Output file is not open!!");
}

File::~File()
{
    this->openFile.close();
    this->writeFile.close();
}

void File::replaceLine(std::string &line, std::string origin, std::string replace)
{
    std::string::size_type start;

    while ((start = line.find(origin)) != -1) {
        line.erase(start, origin.length());
        line.insert(start, replace);
    }
}

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
