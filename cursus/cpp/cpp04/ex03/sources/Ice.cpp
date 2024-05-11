#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice &cls) { *this = cls; }

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &cls)
{
    this->AMateria::operator=(cls);
    return *this;
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}