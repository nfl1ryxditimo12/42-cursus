#include "Zombie.hpp"

int main(void)
{
    Zombie stack = Zombie("stack");
    Zombie *heap1 = new Zombie("heap1");
    Zombie *heap2 = newZombie("heap2");

    stack.announce();
    heap1->announce();
    heap2->announce();
    randomChump("randomChump");

    delete heap1;
    delete heap2;
}
