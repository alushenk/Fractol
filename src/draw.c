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

//void	bresen_init(t_bresenham *b, int x0, int y0, int x1, int y1)
//{
//	b->x0 = x0;
//	b->y0 = y0;
//	b->x1 = x1;
//	b->y1 = y1;
//	b->move_x = x0 < x1 ? 1 : -1;
//	b->move_y = y0 < y1 ? 1 : -1;
//	b->delta_x = abs(b->x1 - b->x0);
//	b->delta_y = abs(b->y1 - b->y0);
//	b->error = b->delta_x - b->delta_y;
//}
//
//int		in_range(int x, int y)
//{
//	if (x < 0 || y < 0 || x >= WIN_SIZE || y >= WIN_SIZE)
//		return (0);
//	return (1);
//}
//
//void	draw_line(int x0, int y0, int x1, int y1, t_map *mlx)
//{
//	t_bresenham b;
//
//	bresen_init(&b, x0, y0, x1, y1);
//	while (b.x0 != b.x1 || b.y0 != b.y1)
//	{
//		if (in_range(b.x0, b.y0))
//			write_pixel(b.x0, b.y0, 255, mlx);
//		b.error2 = b.error * 2;
//		if (b.error2 > -b.delta_y)
//		{
//			b.error -= b.delta_y;
//			b.x0 += b.move_x;
//		}
//		if (b.error2 < b.delta_x)
//		{
//			b.error += b.delta_x;
//			b.y0 += b.move_y;
//		}
//	}
//	if (in_range(x1, y1))
//		write_pixel(x1, y1, 255, mlx);
//}

void	init_color(t_fractal *f)
{
//	f->color = (unsigned char)((0.1 + f->i * 0.03 * 0.2));
//	f->color <<= 8;
//	f->color |= (unsigned char)((0.2 + f->i * 0.03 * 0.3));
//	f->color <<= 8;
//	f->color |= (unsigned char)((0.3 + f->i * 0.03 * 0.1));
	f->color = (unsigned char)((f->i * 9) % 255);
	f->color <<= 16;
	f->color |= (unsigned char)((f->i * 9) % 255);
}

void		draw(t_map *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = mlx_new_image(mlx->init, WIN_SIZE, WIN_SIZE);
	mlx->img_d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->l_size, &mlx->e);

	pthread_t *thread;
	t_fractal *fractal;
	int i;
	int row;

	//fractal и thread в одну структуру
	thread = (pthread_t*)malloc(sizeof(pthread_t) * 12);
	fractal = (t_fractal*)malloc(sizeof(t_fractal) * 12);
	i = 0;
	row = 0;
	while (row < WIN_SIZE)
	{
		fractal[i].mlx = *mlx;
		fractal[i].y = row;
		//pthread_create( &thread[i], NULL, julia, &fractal[i]);
		//pthread_create( &thread[i], NULL, mandelbrot, &fractal[i]);
		if (mlx->figure == 1)
			julia(&fractal[i]);
		else if (mlx->figure == 2)
			mandelbrot(&fractal[i]);
		row += SIZE;
		i++;
	}
	row = 0;
	while (row < i)
	{
		pthread_join(thread[row], NULL);
		row++;
	}
	free(thread);
	free(fractal);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}