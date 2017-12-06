/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:05:20 by ppatel            #+#    #+#             */
/*   Updated: 2017/01/31 19:06:35 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		mlx_pxl_put(t_env *a, int x, int y)
{
	if (x < 0 || x >= WX || y < 0 || y >= WY)
		return ;
	if (a->endian == 0)
	{
		a->imgstr[y * a->sizeline + x * a->bpp / 8 + 2] = a->color.r;
		a->imgstr[y * a->sizeline + x * a->bpp / 8 + 1] = a->color.g;
		a->imgstr[y * a->sizeline + x * a->bpp / 8] = a->color.b;
	}
	else
	{
		a->imgstr[y * a->sizeline + x * a->bpp / 8 + 1] = a->color.r;
		a->imgstr[y * a->sizeline + x * a->bpp / 8 + 2] = a->color.g;
		a->imgstr[y * a->sizeline + x * a->bpp / 8 + 3] = a->color.b;
	}
}

static void		color(t_env *e, int iter)
{
	int		color;

	color = iter * e->c;
	e->color.b = color % 256;
	e->color.g = ((color - e->color.b) / (256)) % 256;
	e->color.r = (color - e->color.b - (e->color.g * 256)) / 65536;
}

int				draw(t_env *a)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < WY)
	{
		x = 0;
		while (x < WX)
		{
			if (a->f == 'm')
				i = mandelbrot(x, y, a);
			else if (a->f == 'j')
				i = julia(x, y, a);
			else if (a->f == 'b')
				i = burning_ship(x, y, a);
			else if (a->f == 'd')
				i = d_rabbit(x, y, a);
			color(a, a->itmax == i ? 0 : i);
			mlx_pxl_put(a, x++, y);
		}
		y++;
	}
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	return (0);
}

static int		ft_init(t_env *a, int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("Use 1 valid Option.\nusage: ./fractol [m | j | b | d]");
		return (1);
	}
	if (av[1][1] || (av[1][0] != 'm' && av[1][0] != 'j' && av[1][0] != 'b'
			&& av[1][0] != 'd'))
	{
		ft_putendl("Invalid Option\nusage: ./fractol [m | j | b | d]");
		return (1);
	}
	a->f = av[1][0];
	a->zoom = 1;
	a->xset = 0;
	a->yset = 0;
	a->itmax = 50;
	a->j = 0;
	a->c = 10000;
	return (0);
}

int				main(int argc, char **argv)
{
	t_env	a;

	if (ft_init(&a, argc, argv))
		return (0);
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, WX, WY, "Fractol");
	a.img = mlx_new_image(a.mlx, WX, WY);
	a.imgstr = mlx_get_data_addr(a.img, &a.bpp, &a.sizeline, &a.endian);
	mlx_expose_hook(a.win, draw, &a);
	mlx_key_hook(a.win, key_hook, &a);
	mlx_mouse_hook(a.win, mouse_hook, &a);
	if (argv[1][0] == 'j')
		mlx_hook(a.win, 6, 1L << 6, mouse_motion, &a);
	mlx_loop(a.mlx);
	return (0);
}
