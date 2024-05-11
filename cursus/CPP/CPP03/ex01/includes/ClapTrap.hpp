#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string     name;
        unsigned int    point;
        unsigned int    energy;
        unsigned int    damage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &cls);
        ~ClapTrap();

        ClapTrap &operator=(const ClapTrap &cls);

        int canNothing(void);
        unsigned int getDamage(void);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
