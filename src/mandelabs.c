/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:37:33 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/20 21:37:35 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_imre(t_fractal *f, int x)
{
	f->c_re = ((double)(x - f->mlx.move_x + 0.5)) / f->mlx.zoom;
	f->c_im = ((double)(f->y - f->mlx.move_y)) / f->mlx.zoom;
	f->new_re = 0;
	f->new_im = 0;
}

static void	count_mandelabs(t_fractal *f)
{
	f->old_re = f->new_re;
	f->old_im = f->new_im;
	f->new_re = f->old_re * f->old_re - f->old_im * f->old_im + f->c_re;
	f->new_im = 2 * fabs(f->old_re * f->old_im) + f->c_im;
}

void		*mandelabs(void *fractal)
{
	int			x;
	t_fractal	f;

	f = *((t_fractal*)fractal);
	f.len = f.y + 100;
	while (f.y < f.len)
	{
		x = 0;
		while (x < WIN_SIZE)
		{
			init_imre(&f, x);
			f.i = -1;
			while (++f.i < f.mlx.max_iter &&
					(f.new_re * f.new_re + f.new_im * f.new_im) < 4)
				count_mandelabs(&f);
			init_color(&f);
			write_pixel(x, f.y, f.color, &f.mlx);
			x++;
		}
		f.y++;
	}
	return (NULL);
}
