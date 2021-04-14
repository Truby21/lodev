/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:54:15 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 21:11:12 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	spdraw(t_data *d, int i)
{
	d->s.sprite_x = d->p.spr[i].x - d->p.player_x;
	d->s.sprite_y = d->p.spr[i].y - d->p.player_y;
	d->s.inv_det = 1.0
		/ (d->p.plane_x * d->p.viewy - d->p.viewx * d->p.plane_y);
	d->s.transform_x = d->s.inv_det
		* (d->p.viewy * d->s.sprite_x - d->p.viewx * d->s.sprite_y);
	d->s.transform_y = d->s.inv_det
		* (-d->p.plane_y * d->s.sprite_x + d->p.plane_x * d->s.sprite_y);
	d->s.sprite_screen_x = (int)((d->p.rx / 2)
			* (1 + d->s.transform_x / d->s.transform_y));
	d->s.v_move_screen = (int)(0.0 / d->s.transform_y);
	d->s.sprite_height = abs((int)(d->p.ry / (d->s.transform_y))) / 1;
	d->s.draw_start_y = -d->s.sprite_height
		/ 2 + d->p.ry / 2 + d->s.v_move_screen;
}

static void	drawsp(t_data *d, int i)
{
	d->s.draw_end_x = d->s.sprite_width / 2 + d->s.sprite_screen_x;
	if (d->s.draw_end_x >= d->p.rx)
		d->s.draw_end_x = d->p.rx - 1;
	d->s.stripe = d->s.draw_start_x - 1;
	while (++d->s.stripe < d->s.draw_end_x)
	{
		d->s.texx = ((int)(256 * (d->s.stripe
						- (-d->s.sprite_width / 2 + d->s.sprite_screen_x))
					* d->t[4].img_w / d->s.sprite_width) / 256);
		if (d->s.transform_y > 0 && d->s.stripe > 0
			&& d->s.stripe < d->p.rx && d->s.transform_y < d->s.zb[d->s.stripe])
		{
			d->s.y = d->s.draw_start_y - 1;
			while (++d->s.y < d->s.draw_end_y)
			{
				d->s.d = (d->s.y - d->s.v_move_screen) * 256
					- d->p.ry * 128 + d->s.sprite_height * 128;
				d->s.texy = ((d->s.d * d->t[4].img_h)
						/ d->s.sprite_height) / 256;
				d->s.color = pixel_take(&d->t[4], d->s.texy, d->s.texx);
				pixel_put(d, d->s.stripe, d->s.y, (int)(*d->s.color));
			}
		}
	}	
}

void	draw_sprite(t_data *d, int i)
{
	while (++i < d->p.qua_sprite)
	{
		spdraw(d, i);
		if (d->s.draw_start_y < 0)
			d->s.draw_start_y = 0;
		d->s.draw_end_y = d->s.sprite_height / 2
			+ d->p.ry / 2 + d->s.v_move_screen;
		if (d->s.draw_end_y >= d->p.ry)
			d->s.draw_end_y = d->p.ry - 1;
		d->s.sprite_width = abs((int)(d->p.ry / (d->s.transform_y))) / 1;
		d->s.draw_start_x = -d->s.sprite_width / 2 + d->s.sprite_screen_x;
		if (d->s.draw_start_x < 0)
			d->s.draw_start_x = 0;
		drawsp(d, i);
	}
}
