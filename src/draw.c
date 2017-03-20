//
// Created by lush on 3/9/17.
//

#include "fractol.h"

void	write_pixel(int x, int y, char *color, t_map *mlx)
{
	int a;

	a = (y * mlx->l_size + (x * (mlx->bpp / 8)));
	mlx->img_d[a] = (char)color[2];
	mlx->img_d[a + 1] = (char)color[1];
	mlx->img_d[a + 2] = (char)color[0];
}

void	init_color(t_fractal *f)
{
	f->color[0] = (char)(sin(f->mlx.frequency * f->i + 0) * 127 + 128);
	f->color[1] = (char)(sin(f->mlx.frequency * f->i + 2) * 127 + 128);
	f->color[2] = (char)(sin(f->mlx.frequency * f->i + 4) * 127 + 128);
}

void		draw(t_map *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = mlx_new_image(mlx->init, WIN_SIZE, WIN_SIZE);
	mlx->img_d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->l_size, &mlx->e);

	t_fractal *fractal;
	int i;
	int row;

	fractal = (t_fractal*)malloc(sizeof(t_fractal) * 12);
	i = 0;
	row = 0;
	while (row < WIN_SIZE)
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
		else if (mlx->figure == 3)
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
				mandelcube(&fractal[i]);
		}
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