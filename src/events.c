//
// Created by Anton Lushenko on 3/10/17.
//

#include "fractol.h"

int key_hook(int key, t_map *mlx)
{
	if (key == KEY_EXIT)
	{
		exit(0);
	}
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

int mouse_hook(int key, int x, int y, t_map *mlx)
{
/*	fr->zx = fr->zx + (fr->zx - x) / 5;
	fr->zy = fr->zy + (fr->zy - y) / 5;
	fr->zoom += fr->zoom / 5;*/


	if (key == MOUSE_WHEEL_UP)
	{
		mlx->moveX += ((mlx->moveX - x) / 5);
		mlx->moveY += ((mlx->moveY - y) / 5);
		mlx->zoom += mlx->zoom / 5;
	}
	else if (key == MOUSE_WHEEL_DOWN)
	{
		mlx->moveX -= ((mlx->moveX - x) / 5);
		mlx->moveY -= ((mlx->moveY - y) / 5);
		mlx->zoom -= mlx->zoom / 5;
	}
	draw(mlx);
	printf("key = %d\t x = %d\t y = %d\n", key, x, y);
	return (0);
}