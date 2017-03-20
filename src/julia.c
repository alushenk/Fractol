/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:37:15 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/20 21:37:16 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_new(t_fractal *f, int x)
{
	f->newRe = ((double)x - f->mlx.moveX) / f->mlx.zoom;
	f->newIm = ((double)f->y - f->mlx.moveY) / f->mlx.zoom;
}

static void	count_julia(t_fractal *f)
{
	f->oldRe = f->newRe;
	f->oldIm = f->newIm;
	f->newRe = f->oldRe * f->oldRe - f->oldIm * f->oldIm + f->cRe;
	f->newIm = 2 * f->oldRe * f->oldIm + f->cIm;
}

void *julia(void *fractal)
{
	int x;
	t_fractal f;

	f = *((t_fractal*)fractal);
	f.cRe = f.mlx.mouseX;
	f.cIm = f.mlx.mouseY;
	f.len = f.y + 100;
	while (f.y < f.len)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			init_new(&f, x);
			f.i = -1;
			while (++f.i < f.mlx.maxIter && (f.newRe * f.newRe + f.newIm * f.newIm) < 4)
				count_julia(&f);
			init_color(&f);
			write_pixel(x, f.y, f.color, &f.mlx);
			x++;
		}
		f.y++;
	}
	return NULL;
}
