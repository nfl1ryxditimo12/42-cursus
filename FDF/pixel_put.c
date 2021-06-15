#include "mlx.h"

int main()
{
	void *mlx;
	void *win;
	int i;
	int j;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "hello");
	i = 0;
	while (i <= 100)
	{
		j = 0;
		while (j <= 100)
		{
			mlx_pixel_put(mlx, win, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	while (i <= 200)
	{
		j = 100;
		while (j <= 200)
		{
			mlx_pixel_put(mlx, win, i, j, 0x000000FF);
			j++;
		}
		i++;
	}
	while (i <= 300)
	{
		j = 200;
		while (j <= 300)
		{
			mlx_pixel_put(mlx, win, i, j, 0x0000FF00);
			j++;
		}
		i++;
	}
	while (i <= 400)
	{
		j = 300;
		while (j <= 400)
		{
			mlx_pixel_put(mlx, win, i, j, 0x000000FF);
			j++;
		}
		i++;
	}
	while (i <= 500)
	{
		j = 400;
		while (j <= 500)
		{
			mlx_pixel_put(mlx, win, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
