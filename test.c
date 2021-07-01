#include <stdio.h>

int main(int ac, char **av, char **en)
{

	if (ac > 1)
		for (int i = 0; en[i]; i++)
			printf ("%s\n", en[i]);
}
