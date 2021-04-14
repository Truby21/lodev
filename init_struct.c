/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:30:46 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 21:14:16 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_one(t_data *d)
{
	d->p.ea = NULL;
	d->p.we = NULL;
	d->p.no = NULL;
	d->p.so = NULL;
	d->p.sp = NULL;
	d->p.mapline = NULL;
	d->p.map = NULL;
	d->p.spr = NULL;
	d->s.zb = NULL;
	d->p.ry = 0;
	d->p.rx = 0;
	d->p.f_color = 0;
	d->p.c_color = 0;
	d->p.i = 1;
	d->p.screen = 0;
	d->p.fl_player = 0;
	d->p.map_width = 0;
	d->p.map_height = 0;
	d->p.qua_sprite = 0;
	d->p.player_x = 0;
	d->p.player_y = 0;
	d->p.viewx = 0;
	d->p.viewy = 0;
	d->p.plane_x = 0;
	d->p.plane_y = 0;
}

static void	init_two(t_data *d)
{
	d->i.addr = NULL;
	d->i.mlx = NULL;
	d->i.win = NULL;
	d->i.img = NULL;
	d->i.bpp = 0;
	d->i.end = 0;
	d->i.length = 0;
	d->k.camleft = 0;
	d->k.camright = 0;
	d->k.up = 0;
	d->k.down = 0;
	d->k.left = 0;
	d->k.right = 0;
	d->k.esc = 0;
	d->t[0].addr = NULL;
	d->t[0].img = NULL;
	d->t[0].bpp = 0;
	d->t[0].img_h = 0;
	d->t[0].img_w = 0;
	d->t[0].len = 0;
	d->t[0].end = 0;
	d->t[1].addr = NULL;
	d->t[1].img = NULL;
	d->t[1].bpp = 0;
	d->t[1].img_h = 0;
}

static void	init_three(t_data *d)
{
	d->t[1].img_w = 0;
	d->t[1].len = 0;
	d->t[1].end = 0;
	d->t[2].addr = NULL;
	d->t[2].img = NULL;
	d->t[2].bpp = 0;
	d->t[2].img_h = 0;
	d->t[2].img_w = 0;
	d->t[2].len = 0;
	d->t[2].end = 0;
	d->t[3].addr = NULL;
	d->t[3].img = NULL;
	d->t[3].bpp = 0;
	d->t[3].img_h = 0;
	d->t[3].img_w = 0;
	d->t[3].len = 0;
	d->t[3].end = 0;
	d->t[4].addr = NULL;
	d->t[4].img = NULL;
	d->t[4].bpp = 0;
	d->t[4].img_h = 0;
	d->t[4].img_w = 0;
	d->t[4].len = 0;
	d->t[4].end = 0;
	d->l.mapx = 0;
}

static void	init_four(t_data *d)
{
	d->l.mapy = 0;
	d->l.stepx = 0;
	d->l.stepy = 0;
	d->l.hit = 0;
	d->l.side = 0;
	d->l.drawstart = 0;
	d->l.drawend = 0;
	d->l.texx = 0;
	d->l.texy = 0;
	d->l.color = 0;
	d->l.time = 0;
	d->l.oldtime = 0;
	d->l.frametime = 0;
	d->l.movespeed = 0;
	d->l.rotspeed = 0;
	d->l.camx = 0;
	d->l.raydirx = 0;
	d->l.raydiry = 0;
	d->l.sidedistx = 0;
	d->l.sidedisty = 0;
	d->l.deltadistx = 0;
	d->l.deltadisty = 0;
	d->l.perp = 0;
	d->l.lineheight = 0;
	d->l.wallx = 0;
}

void	init_struct(t_data *data)
{
	init_one(data);
	init_two(data);
	init_three(data);
	init_four(data);
	init_five(data);
}
