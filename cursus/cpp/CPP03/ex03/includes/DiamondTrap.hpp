#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &cls);
        ~DiamondTrap();

        DiamondTrap &operator=(const DiamondTrap &cls);

        void attack(const std::string &target);
        void whoAmI();
};

#endif