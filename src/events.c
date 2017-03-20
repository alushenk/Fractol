/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:36:34 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/20 21:36:36 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		struct_reset(t_map *mlx, int figure)
{
	mlx->zoom = 200;
	mlx->move_x = WIN_SIZE / 2;
	mlx->move_y = mlx->move_x;
	mlx->max_iter = 20;
	mlx->is_movable = 0;
	mlx->mouse_x = 1;
	mlx->mouse_y = 1;
	mlx->figure = figure;
	mlx->threading_on = 0;
	mlx->frequency = 105;
}

static int	hooks(int key, t_map *mlx)
{
	if (key == KEY_EXIT)
		exit_button();
	else if (key == KEY_MOVE_LEFT)
		mlx->move_x -= STEP_MOVE;
	else if (key == KEY_MOVE_RIGHT)
		mlx->move_x += STEP_MOVE;
	else if (key == KEY_MOVE_UP)
		mlx->move_y -= STEP_MOVE;
	else if (key == KEY_MOVE_DOWN)
		mlx->move_y += STEP_MOVE;
	else if (key == KEY_NUMBER_1)
		mlx->figure = 1;
	else if (key == KEY_NUMBER_2)
		mlx->figure = 2;
	else if (key == KEY_NUMBER_3)
		mlx->figure = 3;
	else if (key == KEY_NUMBER_4)
		mlx->figure = 4;
	else if (key == KEY_FREQUENCY_PLUS)
		mlx->frequency++;
	else if (key == KEY_FREQUENCY_MINUS)
		mlx->frequency--;
	else
		return (1);
	return (0);
}

int			key_hook(int key, t_map *mlx)
{
	if (hooks(key, mlx))
		if (key == KEY_THREADS)
			mlx->threading_on = mlx->threading_on ? 0 : 1;
		else if (key == KEY_RESET)
			struct_reset(mlx, mlx->figure);
		else if (key == KEY_SCALE_INCREASE)
		{
			if (mlx->max_iter < SHRT_MAX)
				mlx->max_iter += STEP;
		}
		else if (key == KEY_SCALE_DECREASE)
		{
			if (mlx->max_iter > 0)
				mlx->max_iter -= STEP;
		}
		else
			return (0);
	draw(mlx);
	return (0);
}

int			mouse_hook(int key, int x, int y, t_map *mlx)
{
	if (key == MOUSE_CLICK_LEFT)
		mlx->is_movable = mlx->is_movable ? 0 : 1;
	else if (key == MOUSE_WHEEL_UP)
	{
		mlx->move_x += ((mlx->move_x - x) / 5);
		mlx->move_y += ((mlx->move_y - y) / 5);
		mlx->zoom += mlx->zoom / 5;
	}
	else if (key == MOUSE_WHEEL_DOWN)
	{
		mlx->move_x -= ((mlx->move_x - x) / 5);
		mlx->move_y -= ((mlx->move_y - y) / 5);
		mlx->zoom -= mlx->zoom / 5;
	}
	draw(mlx);
	return (0);
}

int			mouse_move(int x, int y, t_map *mlx)
{
	if (mlx->is_movable)
	{
		mlx->mouse_x = 4 * (double)x / WIN_SIZE - 2;
		mlx->mouse_y = 4 * (double)y / WIN_SIZE - 2;
		draw(mlx);
	}
	return (0);
}
