/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:43:47 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/18 21:11:15 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "../img/wall.xpm",
			&game->img.width, &game->img.height);
	game->img.ground = mlx_xpm_file_to_image(game->mlx, "../img/ground.xpm",
			&game->img.width, &game->img.height);
	game->img.up = mlx_xpm_file_to_image(game->mlx, "../img/up.xpm",
			&game->img.width, &game->img.height);
	game->img.down = mlx_xpm_file_to_image(game->mlx, "../img/down.xpm",
			&game->img.width, &game->img.height);
	game->img.left = mlx_xpm_file_to_image(game->mlx, "../img/left.xpm",
			&game->img.width, &game->img.height);
	game->img.right = mlx_xpm_file_to_image(game->mlx, "../img/right.xpm",
			&game->img.width, &game->img.height);
	game->img.score = mlx_xpm_file_to_image(game->mlx, "../img/score.xpm",
			&game->img.width, &game->img.height);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx, "../img/enemy.xpm",
			&game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "../img/exit.xpm",
			&game->img.width, &game->img.height);
}

void	minilibx_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->map.col * TILES, game->map.row * TILES, "Garden of Eden");
	img_init(game);
	game->score = 0;
	draw_tiles(game);
}
