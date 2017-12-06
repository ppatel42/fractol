/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:58:52 by ppatel            #+#    #+#             */
/*   Updated: 2017/01/31 19:05:54 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define ZOOM 1.1
# define MOVE 50
# define WX 800
# define WY 800

typedef struct	s_xy
{
	double		x;
	double		y;
}				t_xy;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*imgstr;
	int			bpp;
	int			sizeline;
	char		f;
	int			endian;
	double		zoom;
	int			itmax;
	int			j;
	double		jx;
	double		jy;
	double		xset;
	double		yset;
	int			c;
	t_color		color;
}				t_env;

int				mandelbrot(int x, int y, t_env *a);
int				julia(int x, int y, t_env *a);
int				burning_ship(int x, int y, t_env *a);
int				d_rabbit(int x, int y, t_env *a);
int				mouse_motion(int x, int y, t_env *a);
int				mouse_hook(int button, int x, int y, t_env *a);
int				key_hook(int key, t_env *a);
int				draw(t_env *a);

#endif
