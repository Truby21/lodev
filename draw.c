/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:39:43 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 16:34:03 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color > 0)
	{
		dst = data->i.addr + (y * data->i.length + x * (data->i.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	*pixel_take(t_txtr *txtr, int texy, int texx)
{
	return ((unsigned int *)(txtr->addr + txtr->len * texy
		+ texx * (txtr->bpp / 8)));
}

void	draw_floor_ceiling(t_data *d, int x, int y)
{
	while (++y <= (d->p.ry - 2) / 2)
	{
		while (++x != d->p.rx)
			pixel_put(d, x, y, d->p.c_color);
		x = 0;
	}
	while (y <= d->p.ry - 2)
	{
		while (++x != d->p.rx)
			pixel_put(d, x, y, d->p.f_color);
		x = 0;
		y++;
	}
}
