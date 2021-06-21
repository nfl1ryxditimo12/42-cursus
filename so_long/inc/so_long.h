/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:51:21 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/21 15:35:41 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define TILES 64
# define EVENT_KEYPRESS 2
# define KEY_EXIT 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define SCORE "YOUR SCORE : "
# define STEP "YOUR STEP  : "
# define TEXT 0xEAEAEA

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
	void	*ptr;
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
	int		step;
	int		c_cnt;
}				t_game;

void			ft_frees(t_game *game);
void			ft_free(char *str);

int				program_exit(t_game *game);
void			print_step(t_game *game);
void			print_err(t_game *game, char *err, char *fstr);
void			print_finish(t_game *game, char *message, int score);

void			minilibx_init(t_game *game);

void			read_file(t_game *game, char *file);

char			**ft_split(t_game *game, char *str, int i);

void			check_extension(char *file);
void			check_map(t_game *game);
void			check_col(t_game *game, int len);

void			draw_tiles(t_game *game);
void			draw_ground(t_game *game, int x, int y);
void			draw_player(t_game *game, int x, int y, void *side);

int				press_key(int key, t_game *game);

#endif
