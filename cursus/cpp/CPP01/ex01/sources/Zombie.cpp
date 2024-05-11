#include "Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout << "Zombie is created!" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " is gone..." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
