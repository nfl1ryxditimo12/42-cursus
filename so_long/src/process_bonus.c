/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:09:54 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/21 16:20:55 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void		turn_side(t_game *game, int key)
{
	draw_ground(game, game->map.cur_x, game->map.cur_y);
	if (key == KEY_W)
		draw_player(game, game->img.up);
	else if (key == KEY_S)
		draw_player(game, game->img.down);
	else if (key == KEY_A)
		draw_player(game, game->img.left);
	else if (key == KEY_D)
		draw_player(game, game->img.right);
}

void		process_key(t_game *game, int x, int y, void *side)
{
	int dx;
	int dy;

	game->step++;
	print_step(game);
	dx = get_value(game->map.cur_x - x * TILES);
	dy = get_value(game->map.cur_y - y * TILES);
	game->map.cur_x -= (dx * 64);
	game->map.cur_y -= (dy * 64);
	game->score -= game->map.map[x][y] == 'C' ? 1 : 0;
	game->c_cnt += game->map.map[x][y] == 'C' ? 1 : 0;
	if (game->map.map[x][y] == 'C')
		draw_ground(game, game->map.cur_x, game->map.cur_y);
	else if (game->map.map[x][y] == 'E')
		print_finish(game, game->score == 0 ? "Complete!" : \
				"Not complete!", game->c_cnt);
	else if (game->map.map[x][y] == 'A')
		print_finish(game, "Game Over!", game->c_cnt);
	draw_player(game, side);
	draw_ground(game, game->map.cur_x + dx * TILES,
			game->map.cur_y + dy * TILES);
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
		program_exit(game);
	else if (key == KEY_W && game->map.map[x - 1][y] != '1')
		process_key(game, x - 1, y, game->img.up);
	else if (key == KEY_S && game->map.map[x + 1][y] != '1')
		process_key(game, x + 1, y, game->img.down);
	else if (key == KEY_A && game->map.map[x][y - 1] != '1')
		process_key(game, x, y - 1, game->img.left);
	else if (key == KEY_D && game->map.map[x][y + 1] != '1')
		process_key(game, x, y + 1, game->img.right);
	else if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		turn_side(game, key);
	return (0);
}
