//
// Created by Anton Lushenko on 3/8/17.
//

#include "src/fractol.h"

static void	struct_init(t_map **mlx)
{
	if (*mlx == NULL)
	{
		*mlx = (t_map *)malloc(sizeof(t_map));
	}
	(*mlx)->init = NULL;
	(*mlx)->win = NULL;
	(*mlx)->img = NULL;
	(*mlx)->zoom = 1;
	(*mlx)->moveX = WIN_SIZE / 2;
	(*mlx)->moveY = (*mlx)->moveX;
	(*mlx)->maxIter = 20;
	(*mlx)->isMovable = 0;
	(*mlx)->mouseX = 1;
	(*mlx)->mouseY = 1;
	(*mlx)->figure = 1;
	(*mlx)->threading_on = 0;
}

int			exit_button(void)
{
	ft_putstr("Escape pressed. Exiting..");
	exit(0);
}

int 	main(void)
{
	t_map	*mlx;
	int		fd;

	mlx = NULL;
	struct_init(&mlx);
	mlx->init = mlx_init();
	mlx->win = mlx_new_window(mlx->init, WIN_SIZE, WIN_SIZE, "fractol");
	draw(mlx);
	mlx_hook(mlx->win, 2, 5, key_hook, mlx);
	mlx_hook(mlx->win, 6, 0, mouse_move, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 17, 0L, exit_button, 0);
	mlx_loop(mlx->init);
	return (0);
}