#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Bot_clap_name"), ScavTrap(), FragTrap()
{
    this->name = "Bot";
    std::cout << "DiamondTrap " << this->name << " is created!!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
    this->name = name;
    std::cout << "DiamondTrap " << this->name << " is created!!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cls)
{
    *this = cls;
}

DiamondTrap::~DiamondTrap()
{
    this->whoAmI();
    std::cout << "DiamondTrap " << this->name << " is gone ..." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cls)
{
    std::cout << "Copy assignment operator was called!!" << std::endl;
    this->name = cls.name;
    ClapTrap::name = cls.name + "_clap_name";
    this->point = cls.point;
    this->energy = cls.energy;
    this->damage = cls.damage;

    return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->name;
    std::cout << ", My Clap name is " << ClapTrap::name << std::endl;
}