//
// Created by Anton Lushenko on 3/16/17.
//

#include "fractol.h"

void	mandelbrot(t_map *mlx)
{
	int x;
	int y;
	int i;
	double oldRe;
	double oldIm;
	double newRe;
	double newIm;
	double cRe;
	double cIm;
	int color;
	double zoom;

	mlx->zoom = 0.5 * mlx->zoom * WIN_SIZE / 2;
	y = 0;
	while (++y < WIN_SIZE)
	{
		x = 0;
		while (++x < WIN_SIZE)
		{
			cRe = (x - WIN_SIZE / 2) / (mlx->zoom * (WIN_SIZE / 2)) + mlx->moveX;
			cIm = (y - WIN_SIZE / 2) / (mlx->zoom * (WIN_SIZE / 2)) + mlx->moveY;
			newRe = mlx->moveX;
			newIm = mlx->moveY;
			i = 0;
			while (++i < MAX_ITERATIONS && (newRe * newRe + newIm * newIm) < 4)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
			}
			color = (unsigned char)((i * 9) % 255);
			color <<= 16;
			color |= (unsigned char)((i * 9) % 255);
			write_pixel(x, y, color, mlx);
		}
	}
}