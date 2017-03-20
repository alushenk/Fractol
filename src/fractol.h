//
// Created by Anton Lushenko on 3/8/17.
//

#ifndef FRACTOL_FRACTOL_H
#define FRACTOL_FRACTOL_H

#include <mlx.h>
#include <stdio.h>
# include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <limits.h>
#include "../libft/libft.h"

/*
** window must be quadrate to let program be simple as fuck
*/
#define WIN_SIZE 1000
#define SIZE 100

# define KEY_SCALE_INCREASE 69
# define KEY_SCALE_DECREASE 78
#define KEY_MOVE_RIGHT 124
#define KEY_MOVE_LEFT 123
#define KEY_MOVE_UP 126
#define KEY_MOVE_DOWN 125
#define KEY_RESET 15
#define KEY_THREADS 17

#define KEY_NUMBER_1 18
#define KEY_NUMBER_2 19
#define KEY_NUMBER_3 20

#define MOUSE_CLICK_LEFT 1
#define MOUSE_CLICK_RIGHT 2
#define MOUSE_WHEEL_UP 4
#define MOUSE_WHEEL_DOWN 5

# define KEY_EXIT 53

#define STEP 1

typedef struct		s_map
{
	double			zoom;
	double			moveX;
	double			moveY;
	void			*init;
	void			*win;
	void			*img;
	char			*img_d;
	int				e;
	int				bpp;
	int				l_size;

	short			maxIter;
	int 			isMovable;
	double 			mouseX;
	double 			mouseY;
	int 			figure;
	int 			threading_on;
	int				color_scheme;
	int				frequency;
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
	int y;
	t_map mlx;
	int i;
	double oldRe;
	double oldIm;
	double newRe;
	double newIm;
	double cRe;
	double cIm;
	char color[3];
	int len;
	pthread_t thread;

}					t_fractal;

/*
** draw.c
*/
void	draw(t_map *mlx);
void	write_pixel(int x, int y, char *color, t_map *mlx);
void	init_color(t_fractal *f);
/*
** events.c
*/
int			key_hook(int key, t_map *mlx);
int			mouse_hook(int key, int x, int y, t_map *mlx);
int 		mouse_move(int x, int y, t_map *mlx);
/*
** fractals.c
*/

/*
** julia.c
*/
void *julia(void *fractal);
/*
** mandelbrot.c
*/
void *mandelbrot(void *fractal);
/*
** mandelcube.c
*/
void	*mandelcube(void *fractal);
/*
** main.c
*/
void	struct_init(t_map **mlx, int figure);
int			exit_button(void);

#endif //FRACTOL_FRACTOL_H
