//
// Created by Anton Lushenko on 3/8/17.
//

#include "fractol.h"

void	struct_init(t_map **mlx, int figure)
{
	if (*mlx == NULL)
	{
		*mlx = (t_map *)malloc(sizeof(t_map));
	}
	(*mlx)->init = NULL;
	(*mlx)->win = NULL;
	(*mlx)->img = NULL;
	(*mlx)->zoom = 200;
	(*mlx)->moveX = WIN_SIZE / 2;
	(*mlx)->moveY = (*mlx)->moveX;
	(*mlx)->maxIter = 20;
	(*mlx)->isMovable = 0;
	(*mlx)->mouseX = 1;
	(*mlx)->mouseY = 1;
	(*mlx)->figure = figure;
	(*mlx)->threading_on = 0;
	(*mlx)->frequency = 500;
}

int			exit_button(void)
{
	ft_putstr("Escape pressed. Exiting..");
	exit(0);
}

int 	main(int argc, char **argv)
{
	t_map	*mlx;
	int		fd;

	if ((argc == 2) && ft_isdigit(argv[1][0]))
	{
		mlx = NULL;
		struct_init(&mlx, ft_atoi(argv[1]));
		mlx->init = mlx_init();
		mlx->win = mlx_new_window(mlx->init, WIN_SIZE, WIN_SIZE, "fractol");
		draw(mlx);
		mlx_hook(mlx->win, 2, 5, key_hook, mlx);
		mlx_hook(mlx->win, 6, 0, mouse_move, mlx);
		mlx_mouse_hook(mlx->win, mouse_hook, mlx);
		mlx_hook(mlx->win, 17, 0L, exit_button, 0);
		mlx_loop(mlx->init);
	}
	else
		ft_putstr("usage: ");
	return (0);
}