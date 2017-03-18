//
// Created by Anton Lushenko on 3/10/17.
//

#include "fractol.h"

int key_hook(int key, t_map *mlx)
{
	if (key == KEY_EXIT)
		exit(0);
	else if (key == KEY_MOVE_LEFT)
		mlx->moveX += STEP;
	else if (key == KEY_MOVE_RIGHT)
		mlx->moveX -= STEP;
	else if (key == KEY_MOVE_UP)
		mlx->moveY += STEP;
	else if (key == KEY_MOVE_DOWN)
		mlx->moveY -= STEP;
	else if (key == KEY_SCALE_INCREASE)
	{
		if (mlx->maxIter < SHRT_MAX)
			mlx->maxIter += STEP;
	}
	else if (key == KEY_SCALE_DECREASE)
	{
		if (mlx->maxIter > 0)
			mlx->maxIter -= STEP;
	}
	else
		return (0);
	draw(mlx);
	return (0);
}

int mouse_hook(int key, int x, int y, t_map *mlx)
{
	if (key == MOUSE_CLICK_LEFT)
		mlx->isMovable = mlx->isMovable ? 0 : 1;
	else if (key == MOUSE_WHEEL_UP)
	{
		mlx->moveX += ((mlx->moveX - x) / 10);
		mlx->moveY += ((mlx->moveY - y) / 10);
		mlx->zoom += mlx->zoom / 10;
	}
	else if (key == MOUSE_WHEEL_DOWN)
	{
		mlx->moveX -= ((mlx->moveX - x) / 10);
		mlx->moveY -= ((mlx->moveY - y) / 10);
		mlx->zoom -= mlx->zoom / 10;
	}
	printf("key = %d\t x = %d\t y = %d\n", key, x, y);
	draw(mlx);
	return (0);
}

int mouse_move(int x, int y, t_map *mlx)
{
	if (mlx->isMovable)
	{
		mlx->mouseX = 4 * (double)x / WIN_SIZE - 2;
		mlx->mouseY = 4 * (double)y / WIN_SIZE - 2;
		draw(mlx);
	}
	return (0);
}