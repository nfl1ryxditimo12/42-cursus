/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:34:41 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/18 12:11:01 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**g_tab;
int		g_max_row;
int		g_max_col;
int		g_max;

void	first_location(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_row_size)
	{
		j = -1;
		while (++j < g_col_size)
		{
			if (g_tab[i][j] == g_max)
			{
				g_max_row = i;
				g_max_col = j;
				return ;
			}
		}
	}
}

void	set_tab(void)
{
	int	i;
	int	j;

	i = -1;
	g_tab = (int **)malloc(sizeof(int *) * (g_row_size) + 1);
	while (++i < g_row_size)
	{
		j = -1;
		if (!(g_tab[i] = (int *)malloc(sizeof(int) * (g_col_size))))
			exit(1);
		while (++j < g_col_size)
		{
			if (g_board[i][j] == g_obstacle)
				g_tab[i][j] = 0;
			else
				g_tab[i][j] = 1;
		}
	}
}

void	dp(void)
{
	int	rslt;
	int	i;
	int	j;

	i = 0;
	g_max = 0;
	set_tab();
	while (++i < g_row_size)
	{
		j = 0;
		while (++j < g_col_size)
			if (g_tab[i][j] == 1)
			{
				rslt = g_tab[i - 1][j];
				rslt = rslt < g_tab[i][j - 1] ? rslt : g_tab[i][j - 1];
				rslt = rslt < g_tab[i - 1][j - 1] ? rslt : g_tab[i - 1][j - 1];
				if (rslt > 0)
				{
					g_tab[i][j] = rslt + 1;
					g_max = g_max > g_tab[i][j] ? g_max : g_tab[i][j];
				}
			}
	}
	first_location();
}
