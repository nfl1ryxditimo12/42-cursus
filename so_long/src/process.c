/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:09:54 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/19 16:14:28 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_value(int n)
{
	if (n > 1)
		return (1);
	else if (n < -1)
		return (-1);
	else if (n == 0)
		return (0);
	else
		return (n);
}

void		process_key(t_game *game, int x, int y, void *side)
{
	int dx;
	int dy;

	dx = get_value(game->map.cur_x - x * TILES);
	dy = get_value(game->map.cur_y - y * TILES);
	game->map.cur_x -= (dx * 64);
	game->map.cur_y -= (dy * 64);
	if (game->map.map[x][y] == 'C')
	{
		game->score++;
		game->map.map[x][y] = '0';
		draw_ground(game, game->map.cur_x, game->map.cur_y);
	}
	else if (game->map.map[x][y] == 'E')
		print_finish(game, "Well Done!", game->score);
	else if (game->map.map[x][y] == 'A')
		print_finish(game, "Game Over!", game->score);
	draw_player(game, game->map.cur_x, game->map.cur_y + 15, side);
	draw_ground(game,
			game->map.cur_x + dx * TILES, game->map.cur_y + dy * TILES);
	game->map.map[x][y] = 'P';
	game->map.map[x + dx][y + dy] = '0';
}

int			press_key(int key, t_game *game)
{
	int x;
	int y;

	x = game->map.cur_x / TILES;
	y = game->map.cur_y / TILES;
	if (key == KEY_EXIT)
		print_finish(game, "Program Exit", game->score);
	else if (key == KEY_W && game->map.map[x - 1][y] != '1')
		process_key(game, x - 1, y, game->img.up);
	else if (key == KEY_S && game->map.map[x + 1][y] != '1')
		process_key(game, x + 1, y, game->img.down);
	else if (key == KEY_A && game->map.map[x][y - 1] != '1')
		process_key(game, x, y - 1, game->img.left);
	else if (key == KEY_D && game->map.map[x][y + 1] != '1')
		process_key(game, x, y + 1, game->img.right);
	return (0);
}
