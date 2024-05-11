#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(int ac, char **av)
{
    if (ac < 2)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        for (int i = 1; i < ac; i++)
            for (int j = 0; j < (int)strlen(av[i]); j++)
                cout << static_cast<char>(toupper(av[i][j]));
        
    cout << endl;
}