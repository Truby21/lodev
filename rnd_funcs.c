/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 23:06:45 by truby             #+#    #+#             */
/*   Updated: 2021/04/01 21:16:04 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	screensize(t_data *data);
// {	
// }

// void	save_screen(t_data *data);
// {
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color > 0)
	{
		dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_floor_ceiling(t_data *data, int x, int y)
{
	while (++y <= (data->param.ry - 2) / 2)
	{
		while (++x != data->param.rx)
			my_mlx_pixel_put(data, x, y, data->param.c_color);
		x = 0;
	}
	while (y <= data->param.ry - 2)
	{
		while (++x != data->param.rx)
			my_mlx_pixel_put(data, x, y, data->param.f_color);
		x = 0;
		y++;
	}
}
