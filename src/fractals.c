//
// Created by Anton Lushenko on 3/13/17.
//

#include "fractol.h"

/*
void draw_branch(int x, int y, int size, t_map *mlx)
{
	int y1;
	int increment;

	y1 = y - size;
	increment = size  * 0.7;
	if (increment < 2)
		return ;
	draw_line(x, y, x, y1, mlx);
	draw_line(x, y1, x + increment, y1 - increment, mlx);
	draw_line(x, y1, x - increment, y1 - increment, mlx);
	draw_branch(x + increment, y1 - increment, increment, mlx);
	draw_branch(x - increment, y1 - increment, increment, mlx);
}

void tree(t_map *mlx)
{
	int x;
	int y;
	int iterations;

	iterations = 2;
	//начинаем по центру низа окна
	x = mlx->moveX - 1;
	y = mlx->moveY - 1;
	while (iterations--)
	{
		draw_branch(x, y, 50, mlx);
	}
}
*/