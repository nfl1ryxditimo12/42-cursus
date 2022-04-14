#ifndef FILE_HPP
# define FILE_HPP

# include <iostream>
# include <fstream>

class File
{
    private:
        std::ifstream openFile;
        std::ofstream writeFile;

        void replaceLine(std::string &line, std::string origin, std::string replace);

    public:
        File(std::string filename);
        ~File();

        void replaceFile(std::string origin, std::string replace);
};

#endif
