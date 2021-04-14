/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:33:48 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 16:37:45 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_forward(t_data *d)
{
	if (d->p.map[(int)d->p.player_y][(int)(d->p.player_x + d->p.viewx
		* d->l.movespeed)] != '1'
		&& d->p.map[(int)d->p.player_y][(int)(d->p.player_x + d->p.viewx
			* d->l.movespeed)] != '2')
		d->p.player_x += d->p.viewx * d->l.movespeed;
	if (d->p.map[(int)(d->p.player_y + d->p.viewy * d->l.movespeed)]
		[(int)d->p.player_x] != '1'
		&& d->p.map[(int)(d->p.player_y + d->p.viewy * d->l.movespeed)]
			[(int)d->p.player_x] != '2')
		d->p.player_y += d->p.viewy * d->l.movespeed;
}

void	move_backward(t_data *d)
{
	if (d->p.map[(int)d->p.player_y][(int)(d->p.player_x - d->p.viewx
		* d->l.movespeed)] != '1'
		&& d->p.map[(int)d->p.player_y][(int)(d->p.player_x - d->p.viewx
			* d->l.movespeed)] != '2')
		d->p.player_x -= d->p.viewx * d->l.movespeed;
	if (d->p.map[(int)(d->p.player_y - d->p.viewy * d->l.movespeed)]
		[(int)d->p.player_x] != '1'
		&& d->p.map[(int)(d->p.player_y - d->p.viewy * d->l.movespeed)]
			[(int)d->p.player_x] != '2')
		d->p.player_y -= d->p.viewy * d->l.movespeed;
}

void	move_left(t_data *d)
{
	if (d->p.map[(int)(d->p.player_y - d->p.viewx
			* d->l.movespeed)][(int)d->p.player_x] != '1'
		&& d->p.map[(int)(d->p.player_y - d->p.viewx
			* d->l.movespeed)][(int)d->p.player_x] != '2')
		d->p.player_y -= d->p.viewx * d->l.movespeed;
	if (d->p.map[(int)d->p.player_y]
		[(int)(d->p.player_x + d->p.viewy * d->l.movespeed)] != '1'
		&& d->p.map[(int)d->p.player_y]
			[(int)(d->p.player_x + d->p.viewy * d->l.movespeed)] != '2')
		d->p.player_x += d->p.viewy * d->l.movespeed;
}

void	move_right(t_data *d)
{
	if (d->p.map[(int)(d->p.player_y + d->p.viewx
			* d->l.movespeed)][(int)d->p.player_x] != '1'
		&& d->p.map[(int)(d->p.player_y + d->p.viewx
			* d->l.movespeed)][(int)d->p.player_x] != '2')
		d->p.player_y += d->p.viewx * d->l.movespeed;
	if (d->p.map[(int)d->p.player_y]
		[(int)(d->p.player_x - d->p.viewy * d->l.movespeed)] != '1'
		&& d->p.map[(int)d->p.player_y]
			[(int)(d->p.player_x - d->p.viewy * d->l.movespeed)] != '2')
		d->p.player_x -= d->p.viewy * d->l.movespeed;
}
