/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:08:44 by truby             #+#    #+#             */
/*   Updated: 2021/03/20 21:47:10 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_put_square(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (y++ < i + 30)
	{
		while (x++ < j + 30)
			my_mlx_pixel_put(data, x, y, 0xFF);
		x = j;
	}
	return (1);
}

int	ft_put_square1(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (y++ < i + 30)
	{
		while (x++ < j + 30)
			my_mlx_pixel_put(data, x, y, 0xFFFF);
		x = j;
	}
	return (1);
}

int	ft_put_square_player(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (y++ < i + 30)
	{
		while (x++ < j + 30)
		{
			if (y == i + 15 && x == j + 15)
			{
				data->plx = x;
				data->ply = y;
				my_mlx_pixel_put(data, x, y, 0xF);
			}
			else
				my_mlx_pixel_put(data, x, y, 0xFFAAFF);
		}
		x = j;
	}
	return (1);
}
