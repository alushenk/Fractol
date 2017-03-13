//
// Created by Anton Lushenko on 3/13/17.
//

#include "fractol.h"

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
			newRe = 1.5 * (x - mlx->moveX) / (0.5 * mlx->zoom * WIN_SIZE_X);
			newIm = (y - mlx->moveY) / (0.5 * mlx->zoom * WIN_SIZE_Y);

			i = 0;
			while (i < maxIterations)
			{
				oldRe = newRe;
				oldIm = newIm;

				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;

				if ((newRe * newRe + newIm * newIm) > 4)
					break;
				i++;
			}
			color = (unsigned char)((i * 9) % 255);
			color <<= 8;
			color |= (unsigned char)((i * 8) % 255);
			color <<= 8;
			color |= (unsigned char)((i * 7) % 255);

			write_pixel(x, y, color, mlx);
			y++;
		}
		x++;
	}
}

void	bresen_init(t_bresenham *b, int x0, int y0, int x1, int y1)
{
	b->x0 = x0;
	b->y0 = y0;
	b->x1 = x1;
	b->y1 = y1;
	b->move_x = x0 < x1 ? 1 : -1;
	b->move_y = y0 < y1 ? 1 : -1;
	b->delta_x = abs(b->x1 - b->x0);
	b->delta_y = abs(b->y1 - b->y0);
	b->error = b->delta_x - b->delta_y;
}

int		in_range(int x, int y)
{
	if (x < 0 || y < 0 || x >= WIN_SIZE_X || y >= WIN_SIZE_Y)
		return (0);
	return (1);
}

static void	draw_line(int x0, int y0, int x1, int y1, t_map *mlx)
{
	t_bresenham b;

	bresen_init(&b, x0, y0, x1, y1);
	while (b.x0 != b.x1 || b.y0 != b.y1)
	{
		if (in_range(b.x0, b.y0))
			write_pixel(b.x0, b.y0, 255, mlx);
		b.error2 = b.error * 2;
		if (b.error2 > -b.delta_y)
		{
			b.error -= b.delta_y;
			b.x0 += b.move_x;
		}
		if (b.error2 < b.delta_x)
		{
			b.error += b.delta_x;
			b.y0 += b.move_y;
		}
	}
	if (in_range(x1, y1))
		write_pixel(x1, y1, 255, mlx);
}

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
