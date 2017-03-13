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

void		draw(t_map *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	mlx->img = mlx_new_image(mlx->init, WIN_SIZE_X, WIN_SIZE_Y);
	mlx->img_d = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->l_size, &mlx->e);

	julia(mlx);
	//tree(mlx);

	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}