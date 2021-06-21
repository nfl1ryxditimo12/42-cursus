/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:39:42 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/21 15:37:13 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void		ft_free(char *str)
{
	if (!str)
		return ;
	free(str);
	str = 0;
}

void		ft_frees(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->map.row)
	{
		free(game->map.map[i]);
		game->map.map[i] = 0;
	}
	free(game->map.map);
	game->map.map = 0;
}

int			main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game.map.col = -1;
		check_extension(av[1]);
		read_file(&game, av[1]);
		minilibx_init(&game);
		print_step(&game);
		mlx_loop_hook(game.mlx, &loop_score, &game);
		mlx_hook(game.win, 17, 0, &program_exit, &game);
		mlx_hook(game.win, EVENT_KEYPRESS, 0, &press_key, &game);
		mlx_loop(game.mlx);
	}
	else
		print_err(0, "Useage : ./so_long \"filename\"", 0);
	return (0);
}
