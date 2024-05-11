#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default Constructor" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cls)
{
    std::cout << "WrongAnimal Copy Constructor" << std::endl;
    *this = cls;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cls)
{
    std::cout << "WrongAnimal Copy Assignment Operator" << std::endl;
    this->type = cls.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong animal sound ~" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}
