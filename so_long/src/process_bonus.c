/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 16:09:54 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/20 07:07:19 by seonkim          ###   ########.fr       */
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

void		ft_putnbr(int n)
{
	char nbr;

	if (!n)
		return ;
	ft_putnbr(n / 10);
	nbr = n % 10 + '0';
	write(1, &nbr, 1);
}

void		print_step(t_game *game)
{
	write(1, "YOUR STEP : ", 12);
	if (!game->step)
		write(1, "0", 1);
	else
		ft_putnbr(game->step);
	write(1, "\n", 1);
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
		print_finish(game, game->score == 0 ? "Well Done!" : \
				"Score is not enough!", game->c_cnt);
	else if (game->map.map[x][y] == 'A')
		print_finish(game, "Game Over!", game->c_cnt);
	draw_player(game, game->map.cur_x, game->map.cur_y + 16, side);
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
