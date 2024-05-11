#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default Constructor" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &cls)
{
    std::cout << "Dog Copy Constructor" << std::endl;
    *this = cls;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor" << std::endl;
}

Dog &Dog::operator=(const Dog &cls)
{
    std::cout << "Dog Copy Assignment Operator" << std::endl;
    this->type = cls.type;

    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bow!! Bow!! Bow!!" << std::endl;
}
