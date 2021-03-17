/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:10:26 by truby             #+#    #+#             */
/*   Updated: 2021/03/15 22:58:57 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void				ft_mymlx(t_param *param, int i, int j, int x)
{
	int				y;

	y = 0;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->Rx, param->Ry, "2D");
	while (param->map[++i] != NULL)
	{
		y = y + 30;
		x = 0;
		while (param->map[i][++j] != '\0')
		{
			x = x + 30;
			if (param->map[i][j] == '1')
				ft_put_square(param, x, y);
			else if (param->map[i][j] == '0')
				ft_put_square1(param, x, y);
			else if (param->map[i][j] == 'N')
				ft_put_square_player(param, x, y);
			else
				continue ;
		}
		j = -1;
	}
	mlx_loop(param->mlx);
}
