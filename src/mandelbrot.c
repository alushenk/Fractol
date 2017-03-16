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
	int color;
	double zoom;

	zoom = 0.5 * mlx->zoom * WIN_SIZE / 2;
	y = 0;
	while (++y < WIN_SIZE)
	{
		x = 0;
		while (++x < WIN_SIZE)
		{
			newRe = 1.5 * (x - mlx->moveX) / zoom;
			newIm = (y - mlx->moveY) / zoom;
			i = 0;
			while (++i < MAX_ITERATIONS && (newRe * newRe + newIm * newIm) > 4)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm;
				newIm = 2 * oldRe * oldIm;
			}
			color = (unsigned char)((i * 9) % 255);
			color <<= 16;
			color |= (unsigned char)((i * 9) % 255);
			write_pixel(x, y, color, mlx);
		}
	}
}