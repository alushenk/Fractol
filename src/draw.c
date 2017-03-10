//
// Created by lush on 3/9/17.
//

#include "fractol.h"

void	write_pixel(int x, int y, int color, t_map *mlx)
{
	int a;

	a = (y * mlx->l_size + (x * (mlx->bpp / 8)));
	a += mlx->bpp;
	mlx->img_d[a] = (unsigned char)(color >> 16);
	mlx->img_d[a + 1] = (unsigned char)(color >> 8);
	mlx->img_d[a + 2] = (unsigned char)color;
}

int		in_range(int x, int y)
{
	if (x < 0 || y < 0 || x >= WIN_SIZE_X || y >= WIN_SIZE_Y)
		return (0);
	return (1);
}

void julia(t_map *mlx)
{
    double cRe, cIm;
    double newRe, newIm, oldRe, oldIm;
    int maxIterations = 100;
	int x;
	int y;
	int i;
	int color;

    cRe = -0.70176;
    cIm = -0.3842;

	x = 0;
    while (x < WIN_SIZE_X)
	{
		y = 0;
		while (y < WIN_SIZE_Y)
		{
			newRe = 1.5 * (x - WIN_SIZE_X / 2) / (0.5 * mlx->zoom * WIN_SIZE_X) + mlx->moveX;
			newIm = (y - WIN_SIZE_Y / 2) / (0.5 * mlx->zoom * WIN_SIZE_Y) + mlx->moveY;

			i = 0;
			while (i < maxIterations)
			{
				oldRe = newRe;
				oldIm = newIm;

				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;

				if ((newRe * newRe + newIm * newIm) > 4) break;
				i++;
			}
			color = (unsigned char)((i * 9) % 255);
			color <<= 16;
			color |= (unsigned char)((i * 9) % 255);

			write_pixel(x, y, color, mlx);
			y++;
		}
		x++;
	}
}

void		draw(t_map *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = mlx_new_image(mlx->init, WIN_SIZE_X, WIN_SIZE_Y);
	mlx->img_d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->l_size, &mlx->e);

	julia(mlx);


	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}