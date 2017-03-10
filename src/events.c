//
// Created by Anton Lushenko on 3/10/17.
//

#include "fractol.h"

int			key_hook(int key, t_map *mlx)
{
	if (key == KEY_EXIT)
		exit(0);
	if (key == KEY_MOVE_LEFT)
	{
		mlx->moveX += STEP;
		draw(mlx);
	}
	if (key == KEY_MOVE_RIGHT)
	{
		mlx->moveX -= STEP;
		draw(mlx);
	}
	if (key == KEY_MOVE_UP)
	{
		mlx->moveY += STEP;
		draw(mlx);
	}
	if (key == KEY_MOVE_DOWN)
	{
		mlx->moveY -= STEP;
		draw(mlx);
	}
	if (key == KEY_SCALE_INCREASE)
	{
		mlx->zoom += STEP;
		draw(mlx);
	}
	if (key == KEY_SCALE_DECREASE)
	{
		mlx->zoom -= STEP;
		draw(mlx);
	}
	return (0);
}

int     mouse_hook(int key, int x, int y, t_map *mlx)
{
	if (key == MOUSE_WHEEL_UP)
	{
		mlx->zoom += STEP;
//		if (x > WIN_CENTRE_X)
//			mlx->moveX = (x - WIN_CENTRE_X);
//		else if (x < WIN_CENTRE_X)
//			mlx->moveX = (WIN_CENTRE_X - x);
		//mlx->moveX += mlx->moveX - x;
		//mlx->moveY += mlx->moveY - y;
		draw(mlx);
	}
	if (key == MOUSE_WHEEL_DOWN)
	{
		mlx->zoom -= STEP;
		if (x > WIN_CENTRE_Y)
			mlx->moveY += STEP;
		else if (x < WIN_CENTRE_Y)
			mlx->moveY -= STEP;
		draw(mlx);
	}
	printf("key = %d\t x = %d\t y = %d\n", key, x, y);
	return (0);
}