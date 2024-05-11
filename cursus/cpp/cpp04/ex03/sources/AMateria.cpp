#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) { this->type = type; }

AMateria::AMateria(const AMateria &cls) { *this = cls; }

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &cls)
{
    (void)cls;
    return *this;
}

std::string const &AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter &target)
{
    (void)target;
}