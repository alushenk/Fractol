//
// Created by Anton Lushenko on 3/10/17.
//

#include "fractol.h"

void	struct_reset(t_map *mlx, int figure)
{
	mlx->zoom = 200;
	mlx->moveX = WIN_SIZE / 2;
	mlx->moveY = mlx->moveX;
	mlx->maxIter = 20;
	mlx->isMovable = 0;
	mlx->mouseX = 1;
	mlx->mouseY = 1;
	mlx->figure = figure;
	mlx->threading_on = 0;
}

int key_hook(int key, t_map *mlx)
{
	if (key == KEY_EXIT)
		exit_button();
	else if (key == KEY_MOVE_LEFT)
		mlx->moveX += STEP_MOVE;
	else if (key == KEY_MOVE_RIGHT)
		mlx->moveX -= STEP_MOVE;
	else if (key == KEY_MOVE_UP)
		mlx->moveY += STEP_MOVE;
	else if (key == KEY_MOVE_DOWN)
		mlx->moveY -= STEP_MOVE;
	else if (key == KEY_NUMBER_1)
		mlx->figure = 1;
	else if (key == KEY_NUMBER_2)
		mlx->figure = 2;
	else if (key == KEY_NUMBER_3)
		mlx->figure = 3;
	else if (key == KEY_NUMBER_4)
		mlx->figure = 4;
	else if (key == KEY_RESET)
		struct_reset(mlx, mlx->figure);
	else if (key == KEY_THREADS)
		mlx->threading_on = mlx->threading_on ? 0 : 1;
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
	//printf("key = %d\t x = %d\t y = %d\n", key, x, y);
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