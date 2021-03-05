/*
   * 
   * board를 규칙에 따라 전처리 및 초기화 한다. 
   *
*/

#include <stdlib.h>
#include <stdio.h>

#define N 4

int	*ft_cond(int argc, char *argv);

int	**board_size(void)
{
	int **board;
	int i;

	i = -1;
	board = (int **)malloc(sizeof(int *) * (N + 1));
	while (++i < N)
		board[i] = (int *)malloc(sizeof(int) * (N + 1));
	return (board);
}

int	ft_preprocess(int index, int **board_size)
{
	int row;
	int col;
	int i;

	i = -1;
	if (index < 8)
	{
		while (
	}
	else (index >= 8)
	{
		row = index % 4;

	}
}

int	ft_location(int *condition, int **board)
{
	int i;
	int row;
	int col;

	i = -1;
	while (++i < N * N)
	{
		if (condition[i] == 4)
			ft_preprocess(i, board);
	}
	return (0);
}

int main()
{
	int **arr;
	int i;
	int j;
	
	arr = board_size();
	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < N)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}
