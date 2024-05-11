#include "ClapTrap.hpp"

int main()
{
    ClapTrap a;
    ClapTrap b("Bot2");

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
