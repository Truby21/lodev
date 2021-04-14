/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 01:17:36 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 21:11:30 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	stepsidedist(t_data *d, int x)
{
	d->l.camx = 2 * x / (double)d->p.rx - 1;
	d->l.raydirx = d->p.viewx + d->p.plane_x * d->l.camx;
	d->l.raydiry = d->p.viewy + d->p.plane_y * d->l.camx;
	d->l.mapx = d->p.player_x;
	d->l.mapy = d->p.player_y;
	d->l.deltadistx = deltadist(d->l.raydiry, d->l.raydirx);
	d->l.deltadisty = deltadist(d->l.raydirx, d->l.raydiry);
	d->l.hit = 0;
	if (d->l.raydirx < 0)
		step_side_x(d, -1, (d->p.player_x - d->l.mapx) * d->l.deltadistx);
	else
		step_side_x(d, 1, (d->l.mapx + 1.0 - d->p.player_x) * d->l.deltadistx);
	if (d->l.raydiry < 0)
		step_side_y(d, -1, (d->p.player_y - d->l.mapy) * d->l.deltadisty);
	else
		step_side_y(d, 1, (d->l.mapy + 1.0 - d->p.player_y) * d->l.deltadisty);
}

static void	mapstepside(t_data *d)
{
	while (d->l.hit == 0)
	{
		if (d->l.sidedistx < d->l.sidedisty)
		{
			d->l.sidedistx += d->l.deltadistx;
			d->l.mapx += d->l.stepx;
			d->l.side = 0;
		}
		else
		{
			d->l.sidedisty += d->l.deltadisty;
			d->l.mapy += d->l.stepy;
			d->l.side = 1;
		}
		if (d->p.map[d->l.mapy][d->l.mapx] == '1')
			d->l.hit = 1;
	}
	if (d->l.side == 0)
		d->l.perp = (d->l.mapx - d->p.player_x
				+ (1 - d->l.stepx) / 2) / d->l.raydirx;
	else
		d->l.perp = (d->l.mapy - d->p.player_y
				+ (1 - d->l.stepy) / 2) / d->l.raydiry;
	d->l.lineheight = (int)(d->p.ry / d->l.perp);
	d->l.drawstart = -d->l.lineheight / 2 + d->p.ry / 2;
}

static void	draw_txtr(t_data *d, int x, int y)
{
	if (d->l.side == 0 && d->l.raydirx > 0)
		d->l.texx = d->t[1].img_w - d->l.texx - 1;
	if (d->l.side == 1 && d->l.raydiry < 0)
		d->l.texx = d->t[1].img_w - d->l.texx - 1;
	d->l.step = 1.0 * d->t[1].img_h / d->l.lineheight;
	d->l.texpos = (d->l.drawstart - d->p.ry / 2
			+ d->l.lineheight / 2) * d->l.step;
	y = d->l.drawstart - 1;
	while (++y < d->l.drawend)
	{
		if (d->l.side == 0 && d->l.stepx > 0)
			d->t[5] = d->t[3];
		else if (d->l.side == 0 && d->l.stepx < 0)
			d->t[5] = d->t[2];
		else if (d->l.side == 1 && d->l.stepy < 0)
			d->t[5] = d->t[0];
		else if (d->l.side == 1 && d->l.stepy > 0)
			d->t[5] = d->t[1];
		d->l.texy = (int)d->l.texpos;
		if (d->l.texy >= d->t[5].img_h)
			d->l.texy = d->t[5].img_h - 1;
		d->l.texpos += d->l.step;
		d->l.color = pixel_take(&d->t[5], d->l.texy, d->l.texx);
		pixel_put(d, x, y, (int)(*d->l.color));
	}
}

void	draw_texture(t_data *d, int x, int y)
{
	d->s.zb = malloc(sizeof(double) * d->p.rx);
	if (d->s.zb == NULL)
		ft_error("Error\nError of malloc.", &d->p);
	d->l.time = 30;
	d->l.oldtime = 0;
	while (++x < d->p.rx)
	{
		stepsidedist(d, x);
		mapstepside(d);
		if (d->l.drawstart < 0)
			d->l.drawstart = 0;
		d->l.drawend = d->l.lineheight / 2 + d->p.ry / 2;
		if (d->l.drawend >= d->p.ry)
			d->l.drawend = d->p.ry;
		if (d->l.side == 0)
			d->l.wallx = d->p.player_y + d->l.perp * d->l.raydiry;
		else
			d->l.wallx = d->p.player_x + d->l.perp * d->l.raydirx;
		d->l.wallx -= floor(d->l.wallx);
		d->l.texx = (int)(d->l.wallx * (double)d->t[1].img_w);
		draw_txtr(d, x, y);
		d->s.zb[x] = d->l.perp;
	}
}
