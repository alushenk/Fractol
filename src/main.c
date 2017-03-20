/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:37:24 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/20 21:37:25 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(*mlx)->move_x = WIN_SIZE / 2;
	(*mlx)->move_y = (*mlx)->move_x;
	(*mlx)->max_iter = 20;
	(*mlx)->is_movable = 0;
	(*mlx)->mouse_x = 1;
	(*mlx)->mouse_y = 1;
	(*mlx)->figure = figure;
	(*mlx)->threading_on = 0;
	(*mlx)->frequency = 105;
}

int		exit_button(void)
{
	ft_putstr("Escape pressed. Exiting..");
	exit(0);
}

int		main(int argc, char **argv)
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
