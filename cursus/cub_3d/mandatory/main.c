/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:01:15 by seonkim           #+#    #+#             */
/*   Updated: 2022/06/07 21:58:39 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test(char *filename)
{
	t_var	var;

	if (cub3d_init(&var, filename))
		exit(1);
	mlx_put_image_to_window(var.mlx, var.win, var.image.image, 0, 0);
	mlx_loop_hook(var.mlx, &main_loop, &var);
	mlx_loop(var.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (parse_error(1, ERROR_LEVEL, INVALID_FILENAME));
	test(av[1]);
	system("leaks cub3D | grep Process");
	return (0);
}
