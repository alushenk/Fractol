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
	f->new_re = ((double)x - f->mlx.move_x) / f->mlx.zoom;
	f->new_im = ((double)f->y - f->mlx.move_y) / f->mlx.zoom;
}

static void	count_julia(t_fractal *f)
{
	f->old_re = f->new_re;
	f->old_im = f->new_im;
	f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->c_re;
	f->new_im = 2 * f->old_re * f->old_im + f->c_im;
}

void *julia(void *fractal)
{
	int x;
	t_fractal f;

	f = *((t_fractal*)fractal);
	f.c_re = f.mlx.mouse_x;
	f.c_im = f.mlx.mouse_y;
	f.len = f.y + 100;
	while (f.y < f.len)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			init_new(&f, x);
			f.i = -1;
			while (++f.i < f.mlx.max_iter && (f.new_re * f.new_re + f.new_im * f.new_im) < 4)
				count_julia(&f);
			init_color(&f);
			write_pixel(x, f.y, f.color, &f.mlx);
			x++;
		}
		f.y++;
	}
	return NULL;
}
