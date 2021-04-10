/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 01:17:36 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 17:15:17 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	stepsidedist(t_data *data)
{
	lod.mapx = prm.player_x;
	lod.mapy = prm.player_y;
	lod.deltadistx = deltadist(lod.raydiry, lod.raydirx);
	lod.deltadisty = deltadist(lod.raydirx, lod.raydiry);
	lod.hit = 0;
	if (lod.raydirx < 0)
	{
		lod.stepx = -1;
		lod.sidedistx = (prm.player_x - lod.mapx) * lod.deltadistx;
	}
	else
	{
		lod.stepx = 1;
		lod.sidedistx = (lod.mapx + 1.0 - prm.player_x) * lod.deltadistx;
	}
	if (lod.raydiry < 0)
	{
		lod.stepy = -1;
		lod.sidedisty = (prm.player_y - lod.mapy) * lod.deltadisty;
	}
	else
	{
		lod.stepy = 1;
		lod.sidedisty = (lod.mapy + 1.0 - prm.player_y) * lod.deltadisty;
	}
}

static void	mapstepside(t_data *data)
{
	while (lod.hit == 0)
	{
		if (lod.sidedistx < lod.sidedisty)
		{
			lod.sidedistx += lod.deltadistx;
			lod.mapx += lod.stepx;
			lod.side = 0;
		}
		else
		{
			lod.sidedisty += lod.deltadisty;
			lod.mapy += lod.stepy;
			lod.side = 1;
		}
		if (prm.map[lod.mapy][lod.mapx] == '1')
			lod.hit = 1;
	}
	if (lod.side == 0)
		lod.per = (lod.mapx - prm.player_x + (1 - lod.stepx) / 2) / lod.raydirx;
	else
		lod.per = (lod.mapy - prm.player_y + (1 - lod.stepy) / 2) / lod.raydiry;
	lod.lineheight = (int)(prm.ry / lod.per);
	lod.drawstart = -lod.lineheight / 2 + prm.ry / 2;
	if (lod.drawstart < 0)
		lod.drawstart = 0;
}

static void	draw_txtr(t_data *data, int x, int y)
{
	lod.texx = (int)(lod.wallx * (double)tx[1].img_w);
	if (lod.side == 0 && lod.raydirx > 0)
		lod.texx = tx[1].img_w - lod.texx - 1;
	if (lod.side == 1 && lod.raydiry < 0)
		lod.texx = tx[1].img_w - lod.texx - 1;
	lod.step = 1.0 * tx[1].img_h / lod.lineheight;
	lod.texpos = (lod.drawstart - prm.ry / 2 + lod.lineheight / 2) * lod.step;
	y = lod.drawstart - 1;
	while (++y < lod.drawend)
	{
		if (lod.side == 0 && lod.stepx > 0)
			tx[5] = tx[3];
		else if (lod.side == 0 && lod.stepx < 0)
			tx[5] = tx[2];
		else if (lod.side == 1 && lod.stepy < 0)
			tx[5] = tx[0];
		else if (lod.side == 1 && lod.stepy > 0)
			tx[5] = tx[1];
		lod.texy = (int)lod.texpos;
		if (lod.texy >= tx[5].img_h)
			lod.texy = tx[5].img_h - 1;
		lod.texpos += lod.step;
		lod.color = pixel_take(&tx[5], lod.texy, lod.texx);
		pixel_put(data, x, y, (int)(*lod.color));
	}
}

void	draw_texture(t_data *data, int x, int y)
{
	spsp.p = malloc(sizeof(double) * prm.rx);
	if (spsp.p == NULL)
		ft_error("Error\nError of malloc.", &prm);
	lod.time = 30;
	lod.oldtime = 0;
	while (++x < prm.rx)
	{
		lod.camx = 2 * x / (double)prm.rx - 1;
		lod.raydirx = prm.viewx + prm.plane_x * lod.camx;
		lod.raydiry = prm.viewy + prm.plane_y * lod.camx;
		stepsidedist(data);
		mapstepside(data);
		lod.drawend = lod.lineheight / 2 + prm.ry / 2;
		if (lod.drawend >= prm.ry)
			lod.drawend = prm.ry;
		if (lod.side == 0)
			lod.wallx = prm.player_y + lod.per * lod.raydiry;
		else
			lod.wallx = prm.player_x + lod.per * lod.raydirx;
		lod.wallx -= floor(lod.wallx);
		draw_txtr(data, x, y);
		spsp.p[x] = lod.per;
	}
}
