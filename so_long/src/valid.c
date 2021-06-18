/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:04:04 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/18 20:28:22 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(t_game *game, char *file)
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
		print_err(game, "Invalid filename");
}

void	check_start(t_game *game, int p, int i, int j)
{
	if (p > 1)
		print_err(game, "Sprite is not enough");
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
		print_err(game, "Sprite is not enough");
}

void	check_map(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->map.col)
		if (game->map.map[0][i] != '1')
			print_err(game, "Invalid wall on top");
	i = -1;
	while (++i < game->map.col)
		if (game->map.map[game->map.row - 1][i] != '1')
			print_err(game, "Invalid wall on bottom");
	i = -1;
	while (++i < game->map.row)
		if (game->map.map[i][0] != '1')
			print_err(game, "Invalid wall on left");
	i = -1;
	while (++i < game->map.row)
		if (game->map.map[i][game->map.col - 1] != '1')
			print_err(game, "Invalid wall on right");
	check_sprite(game);
}

void	check_col(t_game *game, int len)
{
	if (game->map.col != -1 && game->map.col != len)
		print_err(game, "Incorrect Line");
	game->map.col = len;
}
