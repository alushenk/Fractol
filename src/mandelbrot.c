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

	//zoom = 0.5 * mlx->zoom * WIN_SIZE / 2;
	y = -1;
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
		{
			cRe = (2 * (double)x / WIN_SIZE - 1) / (mlx->zoom * 0.5) + 0.005;
			cIm = (2 * (double)y / WIN_SIZE - 1) / (mlx->zoom * 0.5) + 0.005;
			newRe = 0;
			newIm = 0;
			i = -1;
			while (++i < MAX_ITERATIONS && (newRe * newRe + newIm * newIm) < 4)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
			}
			//printf("x = %d, y = %d, i = %d\n", x, y, i);
			color = (unsigned char)((i * 4) % 255);
			color <<= 16;
			color |= (unsigned char)((i * 16) % 255);
			write_pixel(x, y, color, mlx);
		}
	}
}