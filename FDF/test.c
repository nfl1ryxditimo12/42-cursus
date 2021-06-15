#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_param
{
	int x;
	int y;
}				t_param;

void param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
}

int key_press(int keycode, t_param *param)
{
	if (keycode == 13)
		param->x++;
	else if (keycode == 1)
		param->x--;
	else if (keycode == 0)
		param->y++;
	else if (keycode == 2)
		param->y--;
	else if (keycode == 53)
		exit(0);
	printf("[x : %d] [y : %d]\n", param->x, param->y);
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	t_param param;

	mlx = mlx_init();
	param_init(&param);
	win = mlx_new_window(mlx, 500, 500, "hello world");
	mlx_hook(win, 2, 0, &key_press, &param);
	mlx_loop(mlx);
}
