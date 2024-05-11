/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:29:56 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/21 16:21:47 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_err(t_game *game, char *err, char *fstr)
{
	while (*err)
		write(1, err++, 1);
	write(1, "\n", 1);
	if (!game)
	{
		ft_free(fstr);
		exit(-1);
	}
	ft_frees(game);
	ft_free(fstr);
	exit(-1);
}

void	putnbr(int n)
{
	char ch_nb;

	if (!n)
		return ;
	putnbr(n / 10);
	ch_nb = n % 10 + 48;
	write(1, &ch_nb, 1);
}

void	print_step(t_game *game)
{
	write(1, "YOUR STEP : ", 12);
	if (!game->step)
		write(1, "0", 1);
	else
		putnbr(game->step);
	write(1, "\n", 1);
}

int		program_exit(t_game *game)
{
	print_finish(game, "Program Exit", game->c_cnt);
	return (0);
}

void	print_finish(t_game *game, char *message, int score)
{
	while (*message)
		write(1, message++, 1);
	write(1, "\n", 1);
	write(1, "Your score : ", 13);
	if (!score)
		write(1, "0", 1);
	else
		putnbr(score);
	write(1, "\n", 1);
	ft_frees(game);
	exit(0);
}
