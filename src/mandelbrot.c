//
// Created by Anton Lushenko on 3/16/17.
//

#include "fractol.h"

void	*mandelbrot(void *f)
{
	int x;
	int i;
	double oldRe;
	double oldIm;
	double newRe;
	double newIm;
	double cRe;
	double cIm;
	int color;
	int len;
	t_fractal fract;

	fract = *((t_fractal*)f);
	len = fract.y + 100;
	while (fract.y < len)
	{
		x = fract.x;
		while (x < WIN_SIZE)
		{
			cRe = (2 * (double)x / WIN_SIZE - 1) / (fract.mlx.zoom * 0.5) + 0.005;
			cIm = (2 * (double)fract.y / WIN_SIZE - 1) / (fract.mlx.zoom * 0.5) + 0.005;
			newRe = 0;
			newIm = 0;
			i = -1;
			while (++i < MAX_ITERATIONS && (newRe * newRe + newIm * newIm) < 4)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe * oldRe - oldIm * oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
			}
			color = (unsigned char)((i * 9) % 255);
			color <<= 16;
			color |= (unsigned char)((i * 9) % 255);
			write_pixel(x, fract.y, color, &fract.mlx);
			x++;
		}
		fract.y++;
	}
	return NULL;
}