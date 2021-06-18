/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:51:21 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/18 21:21:11 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define TILES 64
# define EVENT_KEYPRESS 2
# define EVENT_EXIT 17
# define KEY_EXIT 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define BUFFER_SIZE 1000000
# define MEM_ERR "Memory alloctaion ERROR"

typedef struct	s_img
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
}				t_img;

typedef struct	s_map
{
	char	**map;
	int		cur_x;
	int		cur_y;
	int		row;
	int		col;
}				t_map;

typedef struct	s_game
{
	t_img	img;
	t_map	map;
	void	*mlx;
	void	*win;
	int		score;
}				t_game;

void			ft_free(t_game *game);

void			print_err(t_game *game, char *err);
void			print_finish(t_game *game, char *message, int score);

void			minilibx_init(t_game *game);

void			read_file(t_game *game, char *file);

char			**ft_split(t_game *game, char *str, int i);

void			check_extension(t_game *game, char *file);
void			check_map(t_game *game);
void			check_col(t_game *game, int len);

void			draw_tiles(t_game *game);
void			draw_ground(t_game *game, int x, int y);
void			draw_player(t_game *game, int x, int y, void *side);

#endif
