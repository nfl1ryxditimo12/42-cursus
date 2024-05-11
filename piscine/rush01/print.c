#include <unistd.h>

#define N 4

void	print_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_board(int **board)
{
	int row;
	int col;
	char cur;

	row = 0;
	while (row < N)
	{
		col = 0;
		while (col < N)
		{
			cur =  board[row][col] + '0';
			write(1, &cur, 1);
			write(1, " ", 1);
			col++;
		}
		row++;
		write(1, "\n", 1);
	}	
}
