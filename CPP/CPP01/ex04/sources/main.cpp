#include "File.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 4) 
            throw std::runtime_error("Wrong Input!!");

        File file(av[1]);
        file.replaceFile(av[2], av[3]);

        return (0);
    } catch (std::exception &err) {
        std::cerr << "Error: " << err.what() << std::endl;
        return (1);
    }
}
