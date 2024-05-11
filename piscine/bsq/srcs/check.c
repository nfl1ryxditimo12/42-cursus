/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:55:40 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/18 12:19:44 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	g_arr_free(void)
{
	int	i;

	i = 0;
	while (i < g_row_size + 1)
		free(g_board[i++]);
	free(g_board);
	i = 0;
	while (i < g_row_size)
		free(g_tab[i++]);
	free(g_tab);
}

void	print_error(void)
{
	write(2, "map error\n", 10);
	exit(1);
}

int		board_valid(void)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	g_col_size = 0;
	while (g_board[0][g_col_size])
		g_col_size++;
	i = -1;
	while (++i < g_row_size)
	{
		j = -1;
		while (g_board[i][++j])
		{
			if (!(g_board[i][j] == g_obstacle || g_board[i][j] == g_blank))
				print_error();
			if (g_board[i][j] == g_obstacle)
				cnt++;
		}
		if (j != g_col_size)
			print_error();
	}
	return (cnt != (g_row_size * g_col_size));
}
