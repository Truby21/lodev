/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:33:46 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 16:35:07 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	sortsprites(t_data *d, int i, int j)
{
	t_spr	c;

	while (++i < d->p.qua_sprite)
	{
		while (++j < d->p.qua_sprite - 1)
		{
			if (d->p.spr[j].distance < d->p.spr[j + 1].distance)
			{
				c = d->p.spr[j];
				d->p.spr[j] = d->p.spr[j + 1];
				d->p.spr[j + 1] = c;
			}
		}
		j = -1;
	}
}

void	sort_spr(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->p.qua_sprite)
		d->p.spr[i].distance = ((d->p.player_x - d->p.spr[i].x)
				* (d->p.player_x - d->p.spr[i].x) + (d->p.player_y
					- d->p.spr[i].y) * (d->p.player_y - d->p.spr[i].y));
	sortsprites(d, -1, -1);
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

void	init_five(t_data *d)
{
	d->l.step = 0;
	d->l.texpos = 0;
	d->l.olddirx = 0;
	d->l.oldplanex = 0;
	d->s.sprite_x = 0;
	d->s.sprite_y = 0;
	d->s.inv_det = 0;
	d->s.transform_x = 0;
	d->s.transform_y = 0;
	d->s.sprite_screen_x = 0;
	d->s.v_move_screen = 0;
	d->s.sprite_height = 0;
	d->s.sprite_width = 0;
	d->s.draw_start_x = 0;
	d->s.draw_start_y = 0;
	d->s.draw_end_x = 0;
	d->s.draw_end_y = 0;
	d->s.stripe = 0;
	d->s.texx = 0;
	d->s.texy = 0;
	d->s.y = 0;
	d->s.d = 0;
	d->s.color = 0;
}
