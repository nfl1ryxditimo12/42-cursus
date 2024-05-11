#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    private:

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &cls);
        ~FragTrap();

        FragTrap &operator=(const FragTrap &cls);

        void highFivesGuys();
        void attack(const std::string& target);
};

#endif