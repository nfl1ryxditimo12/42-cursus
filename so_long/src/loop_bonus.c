/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:08:30 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/20 05:50:31 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char			*nbr_to_str(t_game *game, int n)
{
	char	*ret;
	int		size;
	int		tmp;

	size = 0;
	tmp = n;
	if (!n)
		size = 1;
	else
		while (tmp)
		{
			tmp /= 10;
			size++;
		}
	if (!(ret = malloc(size + 1)))
		print_err(game, MEM_ERR, 0);
	ret[size] = 0;
	while (--size >= 0)
	{
		ret[size] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

void			view_score_step(t_game *game)
{
	char	*s_score;
	char	*s_step;

	s_score = nbr_to_str(game, game->score);
	s_step = nbr_to_str(game, game->step);
	mlx_string_put(game->mlx, game->win, 32, ROW, TEXT, STEP);
	mlx_string_put(game->mlx, game->win, 32, ROW + 32, TEXT, SCORE);
	if (game->f_step == game->step)
		mlx_string_put(game->mlx, game->win, 170, ROW, TEXT, s_step);
	else if (game->f_step != game->step)
		mlx_put_image_to_window(game->mlx, game->win,
				game->img.black, 170, ROW - 16);
	if (game->f_score == game->score)
		mlx_string_put(game->mlx, game->win, 170, ROW + 32,
				TEXT, s_score);
	else if (game->f_score != game->score)
		mlx_put_image_to_window(game->mlx, game->win, game->img.black,
				170, ROW + 16);
	game->f_step = game->step;
	game->f_score = game->score;
	ft_free(s_score);
	ft_free(s_step);
}


void			draw_score(t_game *game)
{
	int	i;
	int	j;

	if (!game->img.ptr)
		game->img.ptr = game->img.score;
	else if (game->img.ptr == game->img.score)
		game->img.ptr = game->img.score2;
	else if (game->img.ptr == game->img.score2)
		game->img.ptr = game->img.score;
	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.col)
			if (game->map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
						game->img.ptr, j * 64 + 16, \
						i * 64 + 16);
	}
}

int			loop_score(t_game *game)
{
	int	i;

	view_score_step(game);
	if (game->score == game->c_cnt)
		return (0);
	i = -1;
	while (++i < 40000001)
		if (i == 40000000)
			draw_score(game);
	return (0);
}
