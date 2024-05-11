#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl = Harl();

    switch (ac)
    {
        case 2:
            harl.complain(av[1]);
            break ;
        default:
            harl.complain("NOTHING");
            break ;
    }

    return (0);
}
