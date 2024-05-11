#include "Convert.hpp"

int main(int ac, char **av)
{
    if (ac != 2 || std::string(av[1]).length() == 0) {
        std::cout << "Wrong Input!!" << std::endl;
        return (1);
    }

    Convert convert(av[1]);

    convert.detectType();
    std::cout << "==========================================" << std::endl;
    convert.getType(av[1]);
    std::cout << "==========================================" << std::endl;
    convert.toChar();
    convert.toInt();
    convert.toFloat();
    convert.toDouble();
    std::cout << "==========================================" << std::endl;

    return (0);
}
