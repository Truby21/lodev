/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:10:26 by truby             #+#    #+#             */
/*   Updated: 2021/03/20 21:48:20 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	hooks(int keycode, t_param *param)
{
	if (keycode == 53)
        exit(0);
	// if (keycode == 0)
	// {
		// param->map[param->ply][param->plx] = '0';
		// param->map[param->ply][param->plx - 1] = 'N';
	// }
	// printf("%i", keycode);
}

void	ft_mymlx(t_param *param, int i, int j, int x)
{
	int	y;
	t_data img;

	y = 0;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->Rx, param->Ry, "2D");
	img.img = mlx_new_image(param->mlx, param->Rx, param->Ry);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	while (param->map[++i] != NULL)
	{
		y = y + 30;
		x = 0;
		while (param->map[i][++j] != '\0')
		{
			x = x + 30;
			if (param->map[i][j] == '1')
				ft_put_square(&img, x, y);
			else if (param->map[i][j] == '0')
				ft_put_square1(&img, x, y);
			else if (param->map[i][j] == 'N')
				ft_put_square_player(&img, x, y);
			else
				continue ;
		}
		j = -1;
	}
	mlx_hook(param->win, 2, 1L<<1, hooks, &param);
	mlx_put_image_to_window(param->mlx, param->win, img.img, 0, 0);
	mlx_loop(param->mlx);
}
