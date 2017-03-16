//
// Created by lush on 3/9/17.
//

#include "fractol.h"

void	write_pixel(int x, int y, int color, t_map *mlx)
{
	int a;

	a = (y * mlx->l_size + (x * (mlx->bpp / 8)));
	mlx->img_d[a] = (unsigned char)(color >> 16);
	mlx->img_d[a + 1] = (unsigned char)(color >> 8);
	mlx->img_d[a + 2] = (unsigned char)color;
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
	if (x < 0 || y < 0 || x >= WIN_SIZE || y >= WIN_SIZE)
		return (0);
	return (1);
}

void	draw_line(int x0, int y0, int x1, int y1, t_map *mlx)
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

void		draw(t_map *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = mlx_new_image(mlx->init, WIN_SIZE, WIN_SIZE);
	mlx->img_d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->l_size, &mlx->e);

	pthread_t thread;
	t_fractal ***fractal;
	int x;
	int y;
	int i;
	int j;

/*
	fractal = (t_fractal***)malloc(sizeof(t_fractal**) * (WIN_SIZE / SIZE + 1));
	y = 0;
	i = 0;
	while (y < WIN_SIZE)
	{
		x = 0;
		j = 0;
		fractal[j] = (t_fractal**)malloc(sizeof(t_fractal*) * (WIN_SIZE / SIZE + 1));
		while (x < WIN_SIZE)
		{
			fractal[j][i] = (t_fractal*)malloc(sizeof(t_fractal));
			fractal[j][i]->x = x;
			fractal[j][i]->y = y;
			fractal[j][i]->mlx = *mlx;
			//pthread_create( &thread, NULL, julia, fractal[j][i]);
			julia(fractal[j][i]);
			x += SIZE;
			i++;
		}
		y += SIZE;
		j++;
	}
	//free(fractal);
 */
	mandelbrot(mlx);
	//tree(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}