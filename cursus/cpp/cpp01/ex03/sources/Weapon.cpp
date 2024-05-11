#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
    this->weapon = weapon;
}

Weapon::~Weapon(void)
{
}

const std::string &Weapon::getType(void)
{
    return this->weapon;
}

void Weapon::setType(std::string weapon)
{
    this->weapon = weapon;
}
