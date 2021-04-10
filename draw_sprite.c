/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:54:15 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 16:53:04 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	spdraw(t_data *data, int i)
{
	spsp.sprite_x = prm.spr[i].x - prm.player_x;
	spsp.sprite_y = prm.spr[i].y - prm.player_y;
	spsp.inv_det = 1.0
		/ (prm.plane_x * prm.viewy - prm.viewx * prm.plane_y);
	spsp.transform_x = spsp.inv_det
		* (prm.viewy * spsp.sprite_x - prm.viewx * spsp.sprite_y);
	spsp.transform_y = spsp.inv_det
		* (-prm.plane_y * spsp.sprite_x + prm.plane_x * spsp.sprite_y);
	spsp.sprite_screen_x = (int)((prm.rx / 2)
			* (1 + spsp.transform_x / spsp.transform_y));
	spsp.v_move_screen = (int)(0.0 / spsp.transform_y);
	spsp.sprite_height = abs((int)(prm.ry / (spsp.transform_y))) / 1;
	spsp.draw_start_y = -spsp.sprite_height
		/ 2 + prm.ry / 2 + spsp.v_move_screen;
}

static void	drawsp(t_data *data, int i)
{
	if (spsp.draw_start_x < 0)
		spsp.draw_start_x = 0;
	spsp.draw_end_x = spsp.sprite_width / 2 + spsp.sprite_screen_x;
	if (spsp.draw_end_x >= prm.rx)
		spsp.draw_end_x = prm.rx - 1;
	spsp.stripe = spsp.draw_start_x - 1;
	while (++spsp.stripe < spsp.draw_end_x)
	{
		spsp.texx = ((int)(256 * (spsp.stripe
						- (-spsp.sprite_width / 2 + spsp.sprite_screen_x))
					* tx[4].img_w / spsp.sprite_width) / 256);
		if (spsp.transform_y > 0 && spsp.stripe > 0
			&& spsp.stripe < prm.rx && spsp.transform_y < spsp.p[spsp.stripe])
		{
			spsp.y = spsp.draw_start_y - 1;
			while (++spsp.y < spsp.draw_end_y)
			{
				spsp.d = (spsp.y - spsp.v_move_screen) * 256
					- prm.ry * 128 + spsp.sprite_height * 128;
				spsp.texy = ((spsp.d * tx[4].img_h) / spsp.sprite_height) / 256;
				spsp.color = pixel_take(&tx[4], spsp.texy, spsp.texx);
				pixel_put(data, spsp.stripe, spsp.y, (int)(*spsp.color));
			}
		}
	}	
}

void	draw_sprite(t_data *data, int i)
{
	while (++i < prm.qua_sprite)
	{
		spdraw(data, i);
		if (spsp.draw_start_y < 0)
			spsp.draw_start_y = 0;
		spsp.draw_end_y = spsp.sprite_height / 2
			+ prm.ry / 2 + spsp.v_move_screen;
		if (spsp.draw_end_y >= prm.ry)
			spsp.draw_end_y = prm.ry - 1;
		spsp.sprite_width = abs((int)(prm.ry / (spsp.transform_y))) / 1;
		spsp.draw_start_x = -spsp.sprite_width / 2 + spsp.sprite_screen_x;
		drawsp(data, i);
	}
}
