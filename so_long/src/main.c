/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:39:42 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/18 21:21:25 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		ft_free(t_game *game)
{
	int i;

	if (!game->map.map)
		return ;
	i = -1;
	while (++i < game->map.row)
		free(game->map.map[i]);
	free(game->map.map);
}

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

int			main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game.map.col = -1;
		check_extension(&game, av[1]);
		read_file(&game, av[1]);
		minilibx_init(&game);
		mlx_hook(game.win, EVENT_KEYPRESS, 0, &press_key, &game);
		mlx_loop(game.mlx);
	}
	else
		print_err(&game, "Useage : ./so_long \"filename\"");
	return (0);
}
