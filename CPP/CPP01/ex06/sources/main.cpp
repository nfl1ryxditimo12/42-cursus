#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl = Harl();

    harl.complain((ac == 2) ? av[1] : av[0]);

    return (0);
}
