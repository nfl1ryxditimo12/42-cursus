/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:21:52 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/18 11:28:23 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process(void)
{
	int	i;
	int	j;

	i = g_max_row + 1;
	while (--i > g_max_row - g_max)
	{
		j = g_max_col + 1;
		while (--j > g_max_col - g_max)
			g_board[i][j] = g_fill;
	}
	i = -1;
	while (++i < g_row_size)
	{
		j = -1;
		while (++j < g_col_size)
			write(1, &g_board[i][j], 1);
		write(1, "\n", 1);
	}
}

int 	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 1)
	{
		read_file(0);
		dp();
		process();
	}
	while (++i < argc)
	{
		read_file(argv[i]);
		dp();
		process();
	}
	return (0);
}
