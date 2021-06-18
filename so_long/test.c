/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:26:46 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/18 15:34:58 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TILES 64
#define COL 15
#define ROW 15
#define WIDTH TILES * COL
#define HEIGHT TILES * ROW
#define X_EVENT_KEYPRESS 2
#define X_EVENT_EXIT 17
#define KEYCODE_EXIT 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef struct s_img
{
	void	*img;
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*wall;
	void	*ground;
	void	*apple;
	void	*enemy;
	void	*exit;
//	int		*data;
//	int		bpp;
//	int		size_line;
	int		width;
	int		height;
//	int		endian;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		map[ROW][COL];
	int		cur_x;
	int		cur_y;
	int		score;
}				t_game;

typedef struct s_param
{
	int x;
	int y;
} t_param;

void	minilibx_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "go");
}

void	img_init(t_game *game)
{
	//game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "./source/wall.xpm", &game->img.width, &game->img.height);
	game->img.ground = mlx_xpm_file_to_image(game->mlx, "./source/ground1.xpm", &game->img.width, &game->img.height);
	game->img.up = mlx_xpm_file_to_image(game->mlx, "./source/up.xpm", &game->img.width, &game->img.height);
	game->img.down = mlx_xpm_file_to_image(game->mlx, "./source/down.xpm", &game->img.width, &game->img.height);
	game->img.left = mlx_xpm_file_to_image(game->mlx, "./source/left.xpm", &game->img.width, &game->img.height);
	game->img.right = mlx_xpm_file_to_image(game->mlx, "./source/right.xpm", &game->img.width, &game->img.height);
	game->img.apple = mlx_xpm_file_to_image(game->mlx, "./source/apple.xpm", &game->img.width, &game->img.height);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx, "./source/enemy.xpm", &game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "./source/exit.xpm", &game->img.width, &game->img.height);
	//game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_line, &game->img.endian);
}

void	param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
}

void	draw_tiles(t_game *game)
{
	int row;
	int col;

	row = 0;
	printf("test3\n");
	while (row < ROW)
	{
		col = 0;
		while (col < COL)
		{
			if (game->map[row][col] == 1)
				mlx_put_image_to_window(game->mlx, game->win, game->img.wall, col * TILES, row * TILES);
			else if (game->map[row][col] == 0)
				mlx_put_image_to_window(game->mlx, game->win, game->img.ground, col * TILES, row * TILES);
			else if (game->map[row][col] == 3)
			{
				mlx_put_image_to_window(game->mlx, game->win, game->img.ground, col * TILES, row * TILES);
				mlx_put_image_to_window(game->mlx, game->win, game->img.down, col * TILES + 15, row * TILES);
				game->cur_x = col * TILES;
				game->cur_y = row * TILES + 15;
			}
			else if (game->map[row][col] == 4)
			{
				printf("test5\n");
				mlx_put_image_to_window(game->mlx, game->win, game->img.ground, col * TILES, row * TILES);
				printf("test6\n");
				mlx_put_image_to_window(game->mlx, game->win, game->img.apple, col * TILES + 16, row * TILES + 16);
				printf("test7\n");
			}
			else if (game->map[row][col] == 2)
			{
				//mlx_put_image_to_window(game->mlx, game->win, game->img.ground, col * TILES, row * TILES);
				mlx_put_image_to_window(game->mlx, game->win, game->img.exit, col * TILES, row * TILES);
			}
			col++;
		}
		row++;
	}
}

void	map_init(t_game *game)
{
	int src[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 2, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 4, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 3, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
	int i;
	int j;

	i = -1;
	printf("test4\n");
	memcpy(game->map, src, sizeof(int) * ROW * COL);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%d", game->map[i][j]);
			if (j < COL - 1)
				printf(" ");
		}
		printf("\n");
	}
	draw_tiles(game);
}

int	press_key(int keycode, t_game *game)
{
	int x;
	int y;

	x = game->cur_x / TILES;
	y = game->cur_y / TILES;
	printf("score : %d\n", game->score);
	if (keycode == KEYCODE_EXIT)
		exit(0);
	else if (keycode == KEY_W && (!game->map[x - 1][y] || game->map[x - 1][y] == 4))
	{
		game->cur_x -= 64;
		if (game->map[x - 1][y] == 4)
		{
			game->score++;
			game->map[x - 1][y] = 0;
			mlx_put_image_to_window(game->mlx, game->win, game->img.ground, game->cur_y, game->cur_x);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img.up, game->cur_y, game->cur_x);
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, game->cur_y - 15, game->cur_x + 64);
		game->map[x - 1][y] = 3;
		game->map[x][y] = 0;
	}
	else if (keycode == KEY_S && (!game->map[x + 1][y] || game->map[x + 1][y] == 4))
	{
		game->cur_x += 64;
		if (game->map[x + 1][y] == 4)
		{
			game->score++;
			game->map[x + 1][y] = 0;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img.down, game->cur_y, game->cur_x);
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, game->cur_y - 15, game->cur_x - 64);
		game->map[x + 1][y] = 3;
		game->map[x][y] = 0;
	}
	else if (keycode == KEY_A && (!game->map[x][y - 1] || game->map[x][y - 1] == 4))
	{
		game->cur_y -= 64;
		if (game->map[x][y - 1] == 4)
		{
			game->score++;
			game->map[x][y - 1] = 0;
			mlx_put_image_to_window(game->mlx, game->win, game->img.ground, game->cur_y, game->cur_x);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img.left, game->cur_y, game->cur_x);
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, game->cur_y + 49, game->cur_x);
		game->map[x][y - 1] = 3;
		game->map[x][y] = 0;
	}
	else if (keycode == KEY_D && (!game->map[x][y + 1] || game->map[x][y + 1] == 4))
	{
		game->cur_y += 64;
		if (game->map[x][y + 1] == 4)
		{
			game->score++;
			game->map[x][y + 1] = 0;
		}
		mlx_put_image_to_window(game->mlx, game->win, game->img.right, game->cur_y, game->cur_x);
		mlx_put_image_to_window(game->mlx, game->win, game->img.ground, game->cur_y - 79, game->cur_x);
		game->map[x][y + 1] = 3;
		game->map[x][y] = 0;
	}
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			printf("%d", game->map[i][j]);
			if (j < COL - 1)
				printf(" ");
		}
		printf("\n");
	}
	return (0);
}

int main()
{
	t_game game;
	t_param param;

	minilibx_init(&game);
	img_init(&game);
	printf("test1\n");
	map_init(&game);
	printf("test2\n");
	param_init(&param);
	//mlx_put_image_to_window(game.mlx, game.win, game.img.img, 0, 0);
	printf("test\n");
	game.score = 0;
	mlx_hook(game.win, X_EVENT_KEYPRESS, 0, &press_key, &game);
	mlx_loop(game.mlx);
}
