#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Bot";
	this->point = 100;
	this->energy = 100;
	this->damage = 30;

    std::cout << "ClapTrap " << this->name << " is created!!" << std::endl;
    std::cout << "[ Hit point: " << this->point << ", Energy point: " << this->energy << ", Attack damage: " << this->damage << " ]" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->point = 100;
	this->energy = 100;
	this->damage = 30;

    std::cout << "ClapTrap " << this->name << " is created!!" << std::endl;
    std::cout << "[ Hit point: " << this->point << ", Energy point: " << this->energy << ", Attack damage: " << this->damage << " ]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cls)
{
    *this = cls;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &cls)
{
    this->name = cls.name;
    this->point = cls.point;
    this->energy = cls.energy;
    this->damage = cls.damage;

    return *this;
}

int ClapTrap::canNothing()
{
    if (!this->point) {
        std::cout << "ClapTrap " << this->name << " have no hit point!!" << std::endl;
        return 1;
    } else if (!this->energy) {
        std::cout << "ClapTrap " << this->name << " have no energy!!" << std::endl;
        return 1;
    }
    return 0;
}

unsigned int ClapTrap::getDamage()
{
    return this->damage;
}

void ClapTrap::attack(const std::string& target)
{
    if (canNothing())
        return ;

    this->energy--;
    std::cout << "ClapTrap " << this->name << " attacks " << target;
    std::cout << ", cousing " << this->damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->point <= 0 || amount - this->point < amount)
        this->point = 0;
    else
        this->point -= amount;
    std::cout << "ClapTrap " << this->name << " was attacked by " << amount << " damage. [ left: " << this->point << " ]" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (canNothing())
        return ;

    this->energy--;
    this->point += amount;
    std::cout << "ClapTrap " << this->name << " repaired " << amount << " points by itself. [ left: " << this->point << " ]" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " is gone ..." << std::endl;
    std::cout << "[ Hit point: " << this->point << ", Energy point: " << this->energy << ", Attack damage: " << this->damage << " ]" << std::endl;
}
