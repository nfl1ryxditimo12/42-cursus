#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a;
    DiamondTrap b("dia");

    a.whoAmI();
    b.whoAmI();

    a.attack("dia");
    b.takeDamage(a.getDamage());
    a.attack("dia");
    b.takeDamage(a.getDamage());
    a.attack("dia");
    b.takeDamage(a.getDamage());
    b.beRepaired(80);

    a = b;
    
    b.attack("Bot");
    a.takeDamage(b.getDamage());
    b.attack("Bot");
    a.takeDamage(b.getDamage());
    b.attack("Bot");
    a.takeDamage(b.getDamage());
    
}
