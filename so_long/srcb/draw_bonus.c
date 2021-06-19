/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:34:52 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/20 02:46:07 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_ground(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.ground, y, x);
}

void	draw_player(t_game *game, int x, int y, void *side)
{
	mlx_put_image_to_window(game->mlx, game->win, side, y, x);
}

void	draw(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, x, y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, x, y);
		mlx_put_image_to_window(game->mlx, game->win,
				game->img.score, x + 16, y + 16);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x, y);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, x, y);
		draw_player(game, y, x + 16, game->img.down);
	}
	else if (c == 'A')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, x, y);
		mlx_put_image_to_window(game->mlx, game->win, game->img.enemy, x, y);
	}
}

int		invalid_sprite(char c)
{
	return (c == 'C' || c == 'E' || c == 'P' ||
			c == 'A' || c == '1' || c == '0');
}

void	draw_tiles(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.col)
		{
			if (!invalid_sprite(game->map.map[i][j]))
				print_err(game, "Invalid Sprite", 0);
			draw(game, game->map.map[i][j], j * TILES, i * TILES);
			if (game->map.map[i][j] == 'C')
				game->c_cnt++;
		}
	}
}
