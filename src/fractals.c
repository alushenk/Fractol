//
// Created by Anton Lushenko on 3/13/17.
//

#include "fractol.h"

void *julia(void *f)
{
	double cRe, cIm;
	double newRe, newIm, oldRe, oldIm;
	int i;
	int color;
	double zoom;
	int lenx;
	int leny;
	int x;
	int y;
	t_fractal fract;

	fract = *((t_fractal*)f);

	lenx = fract.x + SIZE;
	leny = fract.y + SIZE;

	cRe = -0.70176;
	cIm = -0.3842;

	//может зум надо перещитывать внутри цикла так как он может меняться из событий
	//zoom = fract->mlx->zoom * WIN_SIZE / 2;
	y = fract.y;
	while (++y < WIN_SIZE)
	{
		x = fract.x;
		while (++x < WIN_SIZE)
		{
			newRe = 1.5 * ((double)x - WIN_SIZE / 2) / fract.mlx->zoom;
			newIm = ((double)y - WIN_SIZE / 2) / fract.mlx->zoom;
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
			//color |= (unsigned char)((i * 8) % 255);
			//color <<= 8;
			color |= (unsigned char)((i * 9) % 255);
			write_pixel(x, y, color, fract.mlx);
		}
	}
	return NULL;
}


/*
void draw_branch(int x, int y, int size, t_map *mlx)
{
	int y1;
	int increment;

	y1 = y - size;
	increment = size  * 0.7;
	if (increment < 2)
		return ;
	draw_line(x, y, x, y1, mlx);
	draw_line(x, y1, x + increment, y1 - increment, mlx);
	draw_line(x, y1, x - increment, y1 - increment, mlx);
	draw_branch(x + increment, y1 - increment, increment, mlx);
	draw_branch(x - increment, y1 - increment, increment, mlx);
}

void tree(t_map *mlx)
{
	int x;
	int y;
	int iterations;

	iterations = 2;
	//начинаем по центру низа окна
	x = mlx->moveX - 1;
	y = mlx->moveY - 1;
	while (iterations--)
	{
		draw_branch(x, y, 50, mlx);
	}
}
*/