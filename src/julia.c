//
// Created by Anton Lushenko on 3/17/17.
//

#include "fractol.h"

void *julia(void *f)
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
	int len;
	t_fractal fract;

	//эти константы меняются по формуле(в тетрадке)
	cRe = -0.70176;
	cIm = -0.3842;

	fract = *((t_fractal*)f);
	len = fract.y + 100;
	while (fract.y < len)
	{
		x = fract.x;
		while (x < WIN_SIZE)
		{
			newRe = ((double)x - fract.mlx.moveX) / fract.mlx.zoom;
			newIm = ((double)fract.y - fract.mlx.moveY) / fract.mlx.zoom;
			i = 0;
			while (++i < MAX_ITERATIONS && (newRe * newRe + newIm * newIm) < 4)
			{
				oldRe = newRe;
				oldIm = newIm;
				//последнее число влияет на форму. берется из мышки
				//a->t.mouse_x = 4 * (double)x / M_X - 2;
				//a->t.mouse_y = 4 * (double)y / M_Y - 2;
				newRe = oldRe * oldRe - oldIm * oldIm + cRe + 1;
				newIm = 2 * oldRe * oldIm + cIm + 1;
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