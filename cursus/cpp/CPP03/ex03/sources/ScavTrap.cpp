#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "ScavTrap default constructor was called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap constructor was called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cls)
{
    *this = cls;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cls)
{
    this->name = cls.name;
    this->point = cls.point;
    this->energy = cls.energy;
    this->damage = cls.damage;

    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor was called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->canNothing())
        return ;

    this->energy--;
    std::cout << "ScavTrap " << this->name << " attacks " << target;
    std::cout << ", cousing " << this->damage << " points of damage!" << std::endl;
}