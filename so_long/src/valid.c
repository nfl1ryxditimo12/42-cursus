/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:04:04 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/19 16:47:49 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *file)
{
	int flag;

	flag = 0;
	while (*file)
		if (*file++ == '.')
			if (*file++ == 'b')
				if (*file++ == 'e')
					if (*file++ == 'r')
						if (*file++ == '\0')
							flag = 1;
	if (!flag)
		print_err(0, "Invalid filename", 0);
}

void	check_start(t_game *game, int p, int i, int j)
{
	if (p > 1)
		print_err(game, "Sprite is not enough", 0);
	game->map.cur_x = i * TILES;
	game->map.cur_y = j * TILES;
}

void	check_sprite(t_game *game)
{
	int i;
	int j;
	int c;
	int e;
	int p;

	i = -1;
	c = 0;
	e = 0;
	p = 0;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'C')
				c++;
			else if (game->map.map[i][j] == 'E')
				e++;
			else if (game->map.map[i][j] == 'P')
				check_start(game, p++, i, j);
		}
	}
	if (!c || (!e || e > 1) || (!p || p > 1))
		print_err(game, "Sprite is not enough", 0);
}

void	check_map(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->map.col)
		if (game->map.map[0][i] != '1')
			print_err(game, "Invalid wall on top", 0);
	i = -1;
	while (++i < game->map.col)
		if (game->map.map[game->map.row - 1][i] != '1')
			print_err(game, "Invalid wall on bottom", 0);
	i = -1;
	while (++i < game->map.row)
		if (game->map.map[i][0] != '1')
			print_err(game, "Invalid wall on left", 0);
	i = -1;
	while (++i < game->map.row)
		if (game->map.map[i][game->map.col - 1] != '1')
			print_err(game, "Invalid wall on right", 0);
	check_sprite(game);
}

void	check_col(t_game *game, int len)
{
	if (game->map.col != -1 && game->map.col != len)
		print_err(game, "Incorrect Line", 0);
	game->map.col = len;
}
