#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Default Constructor" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &cls)
{
    std::cout << "WrongCat Copy Constructor" << std::endl;
    *this = cls;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cls)
{
    std::cout << "WrongCat Copy Assignment Operator" << std::endl;
    this->type = cls.type;

    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Meeeeeeoooowww~" << std::endl;
}
