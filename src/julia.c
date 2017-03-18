//
// Created by Anton Lushenko on 3/17/17.
//

#include "fractol.h"

void *julia(void *fractal)
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
	t_fractal f;

	cRe = -0.70176 + f.mlx.mouseX;
	cIm = -0.3842 + f.mlx.mouseY;

	f = *((t_fractal*)fractal);
	len = f.y + 100;
	while (f.y < len)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			newRe = ((double)x - f.mlx.moveX) / f.mlx.zoom;
			newIm = ((double)f.y - f.mlx.moveY) / f.mlx.zoom;
			i = 0;
			while (++i < f.mlx.maxIter && (newRe * newRe + newIm * newIm) < 4)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + cRe;
				newIm = 2 * oldRe * oldIm + cIm;
			}
			color = (unsigned char)((i * 9) % 255);
			color <<= 16;
			color |= (unsigned char)((i * 9) % 255);
			write_pixel(x, f.y, color, &f.mlx);
			x++;
		}
		f.y++;
	}
	return NULL;
}