#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default Constructor" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &cls)
{
    std::cout << "Cat Copy Constructor" << std::endl;
    *this = cls;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor" << std::endl;
}

Cat &Cat::operator=(const Cat &cls)
{
    std::cout << "Cat Copy Assignment Operator" << std::endl;
    this->type = cls.type;

    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meeeeeeoooowww~" << std::endl;
}
