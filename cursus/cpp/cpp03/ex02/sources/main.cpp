#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap a;
    ScavTrap b("Bot2");
    FragTrap c("Bot3");

    std::cout << std::endl;

    b.guardGate();
    c.highFivesGuys();

    std::cout << std::endl;

    b.attack("bot3");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    b.attack("bot2");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    b.attack("bot2");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    b.attack("bot2");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    c.beRepaired(10);
    std::cout << std::endl;
    c.beRepaired(10);
    std::cout << std::endl;
    b.attack("bot2");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    b.attack("bot2");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    b.attack("bot2");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    b.attack("bot2");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    b.attack("bot2");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    b.attack("bot2");
    c.takeDamage(b.getDamage());
    std::cout << std::endl;
    b.attack("bot2");
    std::cout << std::endl;
    c.beRepaired(10);
    std::cout << std::endl;
}
