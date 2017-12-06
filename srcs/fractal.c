/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:00:21 by ppatel            #+#    #+#             */
/*   Updated: 2017/01/31 18:01:44 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mandelbrot(int x, int y, t_env *a)
{
	t_xy	c;
	t_xy	z;
	t_xy	tmp;
	int		i;

	i = 0;
	c.x = ((x + a->xset) / a->zoom / WX) * 4 - 2;
	c.y = ((y + a->yset) / a->zoom / WY) * 4 - 2;
	z.x = 0;
	z.y = 0;
	while (z.x * z.x + z.y * z.y < 4 && i < a->itmax)
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = tmp.x * tmp.y * 2 + c.y;
		i++;
	}
	return (i);
}

int		julia(int x, int y, t_env *a)
{
	t_xy	c;
	t_xy	z;
	t_xy	tmp;
	int		i;

	i = 0;
	z.x = ((x + a->xset) / a->zoom / WX) * 4 - 2;
	z.y = ((y + a->yset) / a->zoom / WY) * 4 - 2;
	c.x = a->jx;
	c.y = a->jy;
	while (z.x * z.x + z.y * z.y < 4 && i < a->itmax)
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = tmp.x * tmp.y * 2 + c.y;
		i++;
	}
	return (i);
}

int		d_rabbit(int x, int y, t_env *a)
{
	t_xy	c;
	t_xy	z;
	t_xy	tmp;
	int		i;

	i = 0;
	z.x = ((x + a->xset) / a->zoom / WX) * 4 - 2;
	z.y = ((y + a->yset) / a->zoom / WY) * 4 - 2;
	c.x = -0.123;
	c.y = -0.745;
	while (z.x * z.x + z.y * z.y < 4 && i < a->itmax)
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = tmp.x * tmp.y * 2 + c.y;
		i++;
	}
	return (i);
}

int		burning_ship(int x, int y, t_env *a)
{
	t_xy	c;
	t_xy	z;
	t_xy	tmp;
	int		i;

	i = 0;
	c.x = ((x + a->xset) / a->zoom / WX) * 4 - 2;
	c.y = ((y + a->yset) / a->zoom / WY) * 4 - 2;
	z.x = 0;
	z.y = 0;
	while (z.x * z.x + z.y * z.y < 4 && i < a->itmax)
	{
		tmp = z;
		z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		z.y = fabs(tmp.x * tmp.y) * 2 + c.y;
		i++;
	}
	return (i);
}
