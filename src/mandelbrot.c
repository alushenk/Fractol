//
// Created by Anton Lushenko on 3/16/17.
//

#include "fractol.h"

static void	init_imre(t_fractal *f, int x)
{
	f->cRe = ((double)(x - f->mlx.moveX + 0.5)) / f->mlx.zoom;
	f->cIm = ((double)(f->y - f->mlx.moveY)) / f->mlx.zoom;
	f->newRe = 0;
	f->newIm = 0;
}

static void	count_mandelbrot(t_fractal *f)
{
	f->oldRe = f->newRe;
	f->oldIm = f->newIm;
	f->newRe = f->oldRe * f->oldRe - f->oldIm * f->oldIm + f->cRe;
	f->newIm = 2 * f->oldRe * f->oldIm + f->cIm;
}

void	*mandelbrot(void *fractal)
{
	int x;
	t_fractal f;

	f = *((t_fractal*)fractal);
	f.len = f.y + 100;
	while (f.y < f.len)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			init_imre(&f, x);
			f.i = -1;
			while (++f.i < f.mlx.maxIter && (f.newRe * f.newRe + f.newIm * f.newIm) < 4)
				count_mandelbrot(&f);
			init_color(&f);
			write_pixel(x, f.y, f.color, &f.mlx);
			x++;
		}
		f.y++;
	}
	return NULL;
}