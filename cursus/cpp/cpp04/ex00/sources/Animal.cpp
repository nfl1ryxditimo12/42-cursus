#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default Constructor" << std::endl;
    this->type = "animal";
}

Animal::Animal(const Animal &cls)
{
    std::cout << "Animal Copy Constructor" << std::endl;
    *this = cls;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor" << std::endl;
}

Animal &Animal::operator=(const Animal &cls)
{
    std::cout << "Animal Copy Assignment Operator" << std::endl;
    this->type = cls.type;
    return *this;
}

void Animal::makeSound() const
{
}

std::string Animal::getType() const
{
    return this->type;
}
