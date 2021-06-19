/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:08:30 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/19 16:46:19 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int			view_score(t_game *game)
{
	char	*str;
	int	size;

	str = nbr_to_str(game, game->score);
	mlx_string_put(game->mlx, game->win, 32, game->map.col * 64 + 100,
			0xEAEAEA, "YOUR SCORE : ");
	if (game->flag == game->score)
	{
		mlx_string_put(game->mlx, game->win, 170,
				game->map.col * 64 + 100, 0xEAEAEA, str);
		game->flag = 1;
	}
	else if (game->flag != game->score)
	{
		mlx_put_image_to_window(game->mlx, game->win,
				game->img.black, 170, game->map.col * 64 + 64);
		game->flag = 0;
	}
	game->flag = game->score;
	ft_free(str);
	str = 0;
	return (0);
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
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	view_score(game);
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.col)
			if (game->map.map[i][j] == 'C')
				flag = 1;
	}
	if (!flag)
		return (0);
	i = -1;
	while (++i < 40000001)
		if (i == 40000000)
			draw_score(game);
	return (0);
}
