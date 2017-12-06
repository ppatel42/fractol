/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:03:32 by ppatel            #+#    #+#             */
/*   Updated: 2017/01/31 18:16:16 by ppatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_move(t_env *a, int key)
{
	if (key == 126)
		a->yset += MOVE;
	else if (key == 125)
		a->yset -= MOVE;
	else if (key == 123)
		a->xset += MOVE;
	else if (key == 124)
		a->xset -= MOVE;
}

int			key_hook(int key, t_env *a)
{
	mlx_clear_window(a->mlx, a->win);
	if (key == 53)
		exit(0);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move(a, key);
	if (key == 69)
		a->itmax += 5;
	if (key == 78)
		a->itmax -= 5;
	if (key == 49)
		a->c += 10000;
	if (key == 1)
		a->j = !(a->j) ? 1 : 0;
	draw(a);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *a)
{
	mlx_clear_window(a->mlx, a->win);
	if (button == 4 && a->zoom < 1000000000000)
	{
		a->zoom *= ZOOM;
		a->xset = a->xset * ZOOM + (WX - WX / ZOOM) / 2 * ZOOM
			+ (x - WX / 2) * ZOOM - (x - WX / 2);
		a->yset = a->yset * ZOOM + (WY - WY / ZOOM) / 2 * ZOOM
			+ (y - WY / 2) * ZOOM - (y - WY / 2);
	}
	if (button == 5)
	{
		a->zoom /= ZOOM;
		a->xset = a->xset / ZOOM - (WX - WX / ZOOM) / 2 * ZOOM
			- (x - WX / 2) / ZOOM + (x - WX / 2);
		a->yset = a->yset / ZOOM - (WY - WY / ZOOM) / 2 * ZOOM
			- (y - WY / 2) / ZOOM + (y - WY / 2);
	}
	draw(a);
	return (0);
}

int			mouse_motion(int x, int y, t_env *a)
{
	if (a->j != 1)
	{
		a->jx = (double)x / WX * 2 - 1;
		a->jy = (double)y / WY * 2 - 1;
		draw(a);
	}
	return (0);
}
