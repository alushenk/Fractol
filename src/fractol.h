/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alushenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:37:04 by alushenk          #+#    #+#             */
/*   Updated: 2017/03/20 21:37:07 by alushenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <limits.h>
# include "../libft/libft.h"

/*
** window must be quadrate to let program be simple as fuck
*/
# define WIN_SIZE 1000
# define SIZE 100
# define STEP 1
# define STEP_MOVE 20

# define KEY_SCALE_INCREASE 69
# define KEY_SCALE_DECREASE 78
# define KEY_MOVE_RIGHT 124
# define KEY_MOVE_LEFT 123
# define KEY_MOVE_UP 126
# define KEY_MOVE_DOWN 125
# define KEY_RESET 15
# define KEY_THREADS 17
# define KEY_FREQUENCY_PLUS 24
# define KEY_FREQUENCY_MINUS 27
# define KEY_EXIT 53

# define KEY_NUMBER_1 18
# define KEY_NUMBER_2 19
# define KEY_NUMBER_3 20
# define KEY_NUMBER_4 21

# define MOUSE_CLICK_LEFT 1
# define MOUSE_CLICK_RIGHT 2
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

typedef struct		s_map
{
	double			zoom;
	double			move_x;
	double			move_y;
	void			*init;
	void			*win;
	void			*img;
	char			*img_d;
	int				e;
	int				bpp;
	int				l_size;
	short			max_iter;
	int				is_movable;
	double			mouse_x;
	double			mouse_y;
	int				figure;
	int				threading_on;
	int				color_scheme;
	char			frequency;
}					t_map;

typedef struct		s_bresenham
{
	int				move_x;
	int				move_y;
	int				delta_x;
	int				delta_y;
	int				error;
	int				error2;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_bresenham;

typedef struct		s_fractal
{
	int				y;
	t_map			mlx;
	int				i;
	double			old_re;
	double			old_im;
	double			new_re;
	double			new_im;
	double			c_re;
	double			c_im;
	char			color[3];
	int				len;
	pthread_t		thread;

}					t_fractal;

/*
** draw.c
*/
void				draw(t_map *mlx);
void				write_pixel(int x, int y, char *color, t_map *mlx);
void				init_color(t_fractal *f);
/*
** events.c
*/
int					key_hook(int key, t_map *mlx);
int					mouse_hook(int key, int x, int y, t_map *mlx);
int					mouse_move(int x, int y, t_map *mlx);
/*
** julia.c
*/
void				*julia(void *fractal);
/*
** mandelbrot.c
*/
void				*mandelbrot(void *fractal);
/*
** mandelcube.c
*/
void				*mandelcube(void *fractal);
/*
** mandelabs.c
*/
void				*mandelabs(void *fractal);
/*
** main.c
*/
void				struct_init(t_map **mlx, int figure);
int					exit_button(void);

#endif
