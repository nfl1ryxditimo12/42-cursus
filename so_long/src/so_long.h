/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:51:21 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/18 15:56:58 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# define TILES 64
# define WIDTH TILES * COL
# define HEIGHT TILES * ROW
# define EVENT_KEYPRESS 2
# define EVENT_EXIT 17
# define KEY_EXIT 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_img
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*wall;
	void	*ground;
	void	*score;
	void	*enemy;
	void	*exit;
	int		width;
	int		height;
}			t_img;

typedef	struct s_param
{
	int		x;
	int		y;
}				t_param;

typedef struct s_game
{
	t_img	img;
	t_param	param;
	void	*mlx;
	void	*win;
	char	**map;
	int		cur_x;
	int		cur_y;
	int		score;
}				t_game;

#endif
