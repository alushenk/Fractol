//
// Created by Anton Lushenko on 3/8/17.
//

#ifndef FRACTOL_FRACTOL_H
#define FRACTOL_FRACTOL_H

#include <mlx.h>
#include <stdio.h>
# include <stdlib.h>
#include <math.h>
#include "../libft/libft.h"

#define WIN_SIZE_X 1200
#define WIN_SIZE_Y 1000

# define KEY_SCALE_INCREASE 69
# define KEY_SCALE_DECREASE 78
#define KEY_MOVE_RIGHT 124
#define KEY_MOVE_LEFT 123
#define KEY_MOVE_UP 126
#define KEY_MOVE_DOWN 125
#define MOUSE_WHEEL_UP 4
#define MOUSE_WHEEL_DOWN 5
# define KEY_EXIT 53

#define STEP 0.1

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

/*
** draw.c
*/
void		draw(t_map *mlx);
void	write_pixel(int x, int y, int color, t_map *mlx);
/*
** events.c
*/
int			key_hook(int key, t_map *mlx);
int     mouse_hook(int key, int x, int y, t_map *mlx);
/*
** fractals.c
*/
void julia(t_map *mlx);
void tree(t_map *mlx);

#endif //FRACTOL_FRACTOL_H
