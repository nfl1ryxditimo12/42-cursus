#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure &cls) { *this = cls; }

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &cls)
{
    this->AMateria::operator=(cls);
    return *this;
}

AMateria *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}