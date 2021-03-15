/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:31:50 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/15 14:41:25 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	board_valid(void)
{
	int	i;
	int	j;
	char	c;

	i = -1;
	while (++i < g_row_size)
	{
		j = -1;
		while (++j < g_col_size)
		{
			c = g_board[i][j];
			if (c != g_obstacle || c != g_blank)
			{
				print_error(BOARD_ERR);
				exit(1);
			}
		}
	}
}
