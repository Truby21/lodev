/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:08:44 by truby             #+#    #+#             */
/*   Updated: 2021/03/14 00:05:24 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_put_square(t_param *param, int x, int y)
{
	int	i;
	int j;

	i = y;
	j = x;
	while (y++ < i + 30)
	{
		while (x++ < j + 30)
			mlx_pixel_put(param->mlx, param->win, x, y, 0xFF);
		x = j;
	}
	return (1);
}

int		ft_put_square1(t_param *param, int x, int y)
{
	int	i;
	int j;

	i = y;
	j = x;
	while (y++ < i + 30)
	{
		while (x++ < j + 30)
			mlx_pixel_put(param->mlx, param->win, x, y, 0xFFFFFF);
		x = j;
	}
	return (1);
}

int		ft_put_square_player(t_param *param, int x, int y)
{
	int	i;
	int j;

	i = y;
	j = x;
	while (y++ < i + 30)
	{
		while (x++ < j + 30)
			mlx_pixel_put(param->mlx, param->win, x, y, 0xFFFF);
		x = j;
	}
	return (1);
}
