/*
   * 
   * board를 규칙에 따라 전처리 및 초기화 한다. 
   *
*/

#include <stdlib.h>
#include <stdio.h>

#define N 4

int	**ft_condition_check(char *argv);
void	pre_col_up(int **board, int **cond);
void	pre_col_down(int **board, int **cond);
void	pre_row_left(int **board, int **cond);
void	pre_row_right(int **board, int **cond);

int	**board_size(int **cond)
{
	int **board;
	int i;

	i = -1;
	board = (int **)malloc(sizeof(int *) * (N + 1));
	while (++i < N)
		board[i] = (int *)malloc(sizeof(int) * (N + 1));
	pre_col_up(board, cond);
	pre_col_down(board, cond);
	pre_row_left(board, cond);
	pre_row_right(board, cond);
	return (board);
}
