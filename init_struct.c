/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:30:46 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 18:54:24 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_one(t_data *data)
{
	prm.ea = NULL;
	prm.we = NULL;
	prm.no = NULL;
	prm.so = NULL;
	prm.sp = NULL;
	prm.mapline = NULL;
	prm.map = NULL;
	prm.spr = NULL;
	spsp.p = NULL;
	prm.ry = 0;
	prm.rx = 0;
	prm.f_color = 0;
	prm.c_color = 0;
	prm.i = 1;
	prm.screen = 0;
	prm.fl_player = 0;
	prm.map_width = 0;
	prm.map_height = 0;
	prm.qua_sprite = 0;
	prm.player_x = 0;
	prm.player_y = 0;
	prm.viewx = 0;
	prm.viewy = 0;
	prm.plane_x = 0;
	prm.plane_y = 0;
}

static void	init_two(t_data *data)
{
	im.addr = NULL;
	im.mlx = NULL;
	im.win = NULL;
	im.img = NULL;
	im.bpp = 0;
	im.endian = 0;
	im.length = 0;
	ke.camleft = 0;
	ke.camright = 0;
	ke.up = 0;
	ke.down = 0;
	ke.left = 0;
	ke.right = 0;
	ke.esc = 0;
	tx[0].addr = NULL;
	tx[0].img = NULL;
	tx[0].bpp = 0;
	tx[0].img_h = 0;
	tx[0].img_w = 0;
	tx[0].len = 0;
	tx[0].end = 0;
	tx[1].addr = NULL;
	tx[1].img = NULL;
	tx[1].bpp = 0;
	tx[1].img_h = 0;
}

static void	init_three(t_data *data)
{
	tx[1].img_w = 0;
	tx[1].len = 0;
	tx[1].end = 0;
	tx[2].addr = NULL;
	tx[2].img = NULL;
	tx[2].bpp = 0;
	tx[2].img_h = 0;
	tx[2].img_w = 0;
	tx[2].len = 0;
	tx[2].end = 0;
	tx[3].addr = NULL;
	tx[3].img = NULL;
	tx[3].bpp = 0;
	tx[3].img_h = 0;
	tx[3].img_w = 0;
	tx[3].len = 0;
	tx[3].end = 0;
	tx[4].addr = NULL;
	tx[4].img = NULL;
	tx[4].bpp = 0;
	tx[4].img_h = 0;
	tx[4].img_w = 0;
	tx[4].len = 0;
	tx[4].end = 0;
	lod.mapx = 0;
}

static void	init_four(t_data *data)
{
	lod.mapy = 0;
	lod.stepx = 0;
	lod.stepy = 0;
	lod.hit = 0;
	lod.side = 0;
	lod.drawstart = 0;
	lod.drawend = 0;
	lod.texx = 0;
	lod.texy = 0;
	lod.color = 0;
	lod.time = 0;
	lod.oldtime = 0;
	lod.frametime = 0;
	lod.movespeed = 0;
	lod.rotspeed = 0;
	lod.camx = 0;
	lod.raydirx = 0;
	lod.raydiry = 0;
	lod.sidedistx = 0;
	lod.sidedisty = 0;
	lod.deltadistx = 0;
	lod.deltadisty = 0;
	lod.per = 0;
	lod.lineheight = 0;
	lod.wallx = 0;
}

void	init_struct(t_data *data)
{
	init_one(data);
	init_two(data);
	init_three(data);
	init_four(data);
	init_five(data);
}
