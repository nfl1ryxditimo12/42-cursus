#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "FragTrap default constructor was called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap constructor was called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cls)
{
    *this = cls;
}

FragTrap &FragTrap::operator=(const FragTrap &cls)
{
    this->name = cls.name;
    this->point = cls.point;
    this->energy = cls.energy;
    this->damage = cls.damage;

    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor was called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name << " high Fives Guys." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (this->canNothing())
        return ;

    this->energy--;
    std::cout << "FragTrap " << this->name << " attacks " << target;
    std::cout << ", cousing " << this->damage << " points of damage!" << std::endl;
}