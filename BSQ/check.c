/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:55:40 by seonkim           #+#    #+#             */
/*   Updated: 2021/03/15 14:03:03 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	board_check(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_row_size)
	{
		j = 0;
		while (g_board[i][j])
			j++;
		if (g_col_size != j)
		{
			print_error(COL_ERR);
			exit(1);
		}
	}
	return (1);
}
