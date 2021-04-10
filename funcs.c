/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:33:46 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 18:53:51 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	sortsprites(t_data *data, int i, int j)
{
	t_spr	c;

	while (++i < prm.qua_sprite)
	{
		while (++j < prm.qua_sprite - 1)
		{
			if (spri[j].distance < spri[j + 1].distance)
			{
				c = spri[j];
				spri[j] = spri[j + 1];
				spri[j + 1] = c;
			}
		}
		j = -1;
	}
}

void	sort_spr(t_data *data)
{
	int	i;

	i = -1;
	while (++i < prm.qua_sprite)
		spri[i].distance = ((prm.player_x - spri[i].x)
				* (prm.player_x - spri[i].x) + (prm.player_y - spri[i].y)
				* (prm.player_y - spri[i].y));
	sortsprites(data, -1, -1);
}

double	deltadist(double rayone, double raytwo)
{
	if (rayone == 0)
		return (0);
	else
	{
		if (raytwo == 0)
			return (1);
		else
			return (fabs(1 / raytwo));
	}
}

void	init_five(t_data *data)
{
	lod.step = 0;
	lod.texpos = 0;
	lod.olddirx = 0;
	lod.oldplanex = 0;
	spsp.sprite_x = 0;
	spsp.sprite_y = 0;
	spsp.inv_det = 0;
	spsp.transform_x = 0;
	spsp.transform_y = 0;
	spsp.sprite_screen_x = 0;
	spsp.v_move_screen = 0;
	spsp.sprite_height = 0;
	spsp.sprite_width = 0;
	spsp.draw_start_x = 0;
	spsp.draw_start_y = 0;
	spsp.draw_end_x = 0;
	spsp.draw_end_y = 0;
	spsp.stripe = 0;
	spsp.texx = 0;
	spsp.texy = 0;
	spsp.y = 0;
	spsp.d = 0;
	spsp.color = 0;
}
