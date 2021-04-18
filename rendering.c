/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:51:33 by truby             #+#    #+#             */
/*   Updated: 2021/04/14 19:18:06 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	render(t_data *d)
{
	d->i.img = mlx_new_image(d->i.win, d->p.rx, d->p.ry);
	d->i.addr = mlx_get_data_addr(d->i.img, &d->i.bpp, &d->i.length, &d->i.end);
	if (d->p.screen)
		mlx_destroy_window(d->i.mlx, d->i.win);
	mlx_do_sync(d->i.mlx);
	draw_floor_ceiling(d, 0, 0);
	draw_texture(d, -1, 0);
	if (d->p.qua_sprite)
	{
		sort_spr(d);
		draw_sprite(d, -1);
	}
	moving(d);
	if (d->s.zb != NULL)
		free(d->s.zb);
	if (d->p.screen)
		screenshot(d);
	else
		mlx_put_image_to_window(d->i.mlx, d->i.win, d->i.img, 0, 0);
	mlx_destroy_image(d->i.mlx, d->i.img);
	d->i.img = NULL;
	d->i.addr = NULL;
	d->s.zb = NULL;
	return (0);
}
