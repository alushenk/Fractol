/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:36:09 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/20 21:36:25 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		write_pixel(int x, int y, char *color, t_map *mlx)
{
	int a;

	a = (y * mlx->l_size + (x * (mlx->bpp / 8)));
	mlx->img_d[a] = (char)color[2];
	mlx->img_d[a + 1] = (char)color[1];
	mlx->img_d[a + 2] = (char)color[0];
}

void		init_color(t_fractal *f)
{
	f->color[0] = (char)(sin(f->mlx.frequency * f->i + 0) * 127 + 128);
	f->color[1] = (char)(sin(f->mlx.frequency * f->i + 2) * 127 + 128);
	f->color[2] = (char)(sin(f->mlx.frequency * f->i + 4) * 127 + 128);
}

static int	fractals0(t_fractal *fractal, int i, int row, t_map *mlx)
{
	fractal[i].mlx = *mlx;
	fractal[i].y = row;
	if (mlx->figure == 1)
	{
		if (mlx->threading_on)
			pthread_create(&fractal[i].thread, NULL, julia, &fractal[i]);
		else
			julia(&fractal[i]);
	}
	else if (mlx->figure == 2)
	{
		if (mlx->threading_on)
			pthread_create(&fractal[i].thread, NULL, mandelbrot, &fractal[i]);
		else
			mandelbrot(&fractal[i]);
	}
	else
		return (0);
	return (1);
}

static int	fractals1(t_fractal *fractal, int i, t_map *mlx)
{
	if (mlx->figure == 3)
	{
		if (mlx->threading_on)
			pthread_create(&fractal[i].thread, NULL, mandelcube, &fractal[i]);
		else
			mandelcube(&fractal[i]);
	}
	else if (mlx->figure == 4)
	{
		if (mlx->threading_on)
			pthread_create(&fractal[i].thread, NULL, mandelabs, &fractal[i]);
		else
			mandelabs(&fractal[i]);
	}
	else
		return (0);
	return (1);
}

void		draw(t_map *mlx)
{
	t_fractal	*fractal;
	int			i;
	int			row;

	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = mlx_new_image(mlx->init, WIN_SIZE, WIN_SIZE);
	mlx->img_d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->l_size, &mlx->e);
	fractal = (t_fractal*)malloc(sizeof(t_fractal) * 12);
	i = 0;
	row = 0;
	while (row < WIN_SIZE)
	{
		(fractals0(fractal, i, row, mlx) || fractals1(fractal, i, mlx));
		row += SIZE;
		i++;
	}
	row = 0;
	while (mlx->threading_on && row < i)
	{
		pthread_join(fractal[row].thread, NULL);
		row++;
	}
	free(fractal);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}
