#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

#define N 4

void	print_str(char *c);
int	**ft_condition_check(char **argv);
int	**board_size(int **cond);

int	main(int argc, char **argv)
{
	int **condition;
	int **board;

	if (argc == 2)
	{
		condition = ft_condition_check(argv);
		board = board_size(condition);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				printf("%d ", board[i][j]);
			printf("\n");
		}
	}
	else
		print_str("Input Error!");
	write(1, "\n", 1);
	return (0);
}
