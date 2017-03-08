//
// Created by Anton Lushenko on 3/8/17.
//

#include "fractol.h"

int 	main(int argc, char **argv)
{
	void *init;
	void *win;


	init = mlx_init();
	win = mlx_new_window(init, WIN_SIZE_X, WIN_SIZE_Y, argv[1]);



	//mlx_hook(win, 2, 5, key_hook, mlx);
	//mlx_hook(win, 17, 0L, exit_button, 0);
	mlx_loop(init);
	return (0);
}