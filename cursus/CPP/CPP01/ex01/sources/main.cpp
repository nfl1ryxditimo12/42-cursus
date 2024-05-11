#include "Zombie.hpp"

int main(void)
{
    int num = 5;
    Zombie *horde = zombieHorde(num, "zombie");

    for (int i = 0; i < num; i++) {
        horde[i].announce();
    }

    delete [] horde;
}
