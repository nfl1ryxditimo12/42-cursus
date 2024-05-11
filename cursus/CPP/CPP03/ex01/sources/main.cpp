#include "ScavTrap.hpp"

int main()
{
    ScavTrap a;
    ScavTrap b("Bot2");

    std::cout << std::endl;

    b.guardGate();

    std::cout << std::endl;

    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    b.beRepaired(10);
    std::cout << std::endl;
    b.beRepaired(10);
    std::cout << std::endl;
    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    a.attack("bot2");
    b.takeDamage(a.getDamage());
    std::cout << std::endl;
    a.attack("bot2");
    std::cout << std::endl;
    b.beRepaired(10);
    std::cout << std::endl;
    
    return (0);
}
