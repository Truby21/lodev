/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:51:33 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 19:20:36 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render(t_data *data)
{
	mlx_do_sync(im.mlx);
	if (prm.screen)
		save_screen(data);
	im.img = mlx_new_image(im.win, prm.rx, prm.ry);
	im.addr = mlx_get_data_addr(im.img, &im.bpp, &im.length, &im.endian);
	draw_floor_ceiling(data, 0, 0);
	draw_texture(data, -1, 0);
	if (prm.qua_sprite)
	{
		sort_spr(data);
		draw_sprite(data, -1);
	}
	if (spsp.p != NULL)
		free(spsp.p);
	moving(data);
	if (prm.screen)
		screenshot(data);
	else
		mlx_put_image_to_window(im.mlx, im.win, im.img, 0, 0);
	mlx_destroy_image(im.mlx, im.img);
	im.img = NULL;
	im.addr = NULL;
	spsp.p = NULL;
	return (0);
}
