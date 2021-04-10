/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:39:43 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 16:43:14 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color > 0)
	{
		dst = im.addr + (y * im.length + x * (im.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	*pixel_take(t_txtr *txtr, int texy, int texx)
{
	return ((unsigned int *)(txtr->addr + txtr->len * texy
		+ texx * (txtr->bpp / 8)));
}

void	draw_floor_ceiling(t_data *data, int x, int y)
{
	while (++y <= (prm.ry - 2) / 2)
	{
		while (++x != prm.rx)
			pixel_put(data, x, y, prm.c_color);
		x = 0;
	}
	while (y <= prm.ry - 2)
	{
		while (++x != prm.rx)
			pixel_put(data, x, y, prm.f_color);
		x = 0;
		y++;
	}
}
