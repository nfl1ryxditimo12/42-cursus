#include <stdio.h>

#define N 4

int	**ft_condition_check(char **argv);
int	**board_size(void);


void	pre_col_up(int **board, int **cond)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < N)
	{
		if (cond[0][i] == 4)
			while (++j < N)
				board[j][i] = j + 1;
		else if (cond[0][i] == 1)
			board[0][i] = 4;
	}
}

void	pre_col_down(int **board, int **cond)
{
	int i;
	int j;

	i = -1;
	j = 4;
	while (++i < N)
	{
		if (cond[1][i] == 4)
			while (--j >= 0)
				board[j][i] = j + 1;
		else if (cond[1][i] == 1)
			board[3][i] = 4;
	}
}

void	pre_row_left(int **board, int **cond)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < N)
	{
		if (cond[2][i] == 4)
			while (++j < N)
				board[i][j] = j + 1;
		else if (cond[2][i] == 1)
			board[i][0] = 4;
	}
}

void	pre_row_right(int **board, int **cond)
{
	int i;
	int j;

	i = -1;
	j = 4;
	while (++i < N)
	{
		if (cond[3][i] == 4)
			while (--j >= 0)
				board[i][j] = j + 1;
		else if (cond[3][i] == 1)
			board[i][3] = 4;
	}
}
