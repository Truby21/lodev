/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:33:48 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 13:49:23 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_forward(t_data *data)
{
	if (prm.map[(int)prm.player_y][(int)(prm.player_x + prm.viewx
		* lod.movespeed)] != '1'
		&& prm.map[(int)prm.player_y][(int)(prm.player_x + prm.viewx
			* lod.movespeed)] != '2')
		prm.player_x += prm.viewx * lod.movespeed;
	if (prm.map[(int)(prm.player_y + prm.viewy * lod.movespeed)]
		[(int)prm.player_x] != '1'
		&& prm.map[(int)(prm.player_y + prm.viewy * lod.movespeed)]
			[(int)prm.player_x] != '2')
		prm.player_y += prm.viewy * lod.movespeed;
}

void	move_backward(t_data *data)
{
	if (prm.map[(int)prm.player_y][(int)(prm.player_x - prm.viewx
		* lod.movespeed)] != '1'
		&& prm.map[(int)prm.player_y][(int)(prm.player_x - prm.viewx
			* lod.movespeed)] != '2')
		prm.player_x -= prm.viewx * lod.movespeed;
	if (prm.map[(int)(prm.player_y - prm.viewy * lod.movespeed)]
		[(int)prm.player_x] != '1'
		&& prm.map[(int)(prm.player_y - prm.viewy * lod.movespeed)]
			[(int)prm.player_x] != '2')
		prm.player_y -= prm.viewy * lod.movespeed;
}

void	move_left(t_data *data)
{
	if (prm.map[(int)(prm.player_y - prm.viewx
			* lod.movespeed)][(int)prm.player_x] != '1'
		&& prm.map[(int)(prm.player_y - prm.viewx
			* lod.movespeed)][(int)prm.player_x] != '2')
		prm.player_y -= prm.viewx * lod.movespeed;
	if (prm.map[(int)prm.player_y]
		[(int)(prm.player_x + prm.viewy * lod.movespeed)] != '1'
		&& prm.map[(int)prm.player_y]
			[(int)(prm.player_x + prm.viewy * lod.movespeed)] != '2')
		prm.player_x += prm.viewy * lod.movespeed;
}

void	move_right(t_data *data)
{
	if (prm.map[(int)(prm.player_y + prm.viewx
			* lod.movespeed)][(int)prm.player_x] != '1'
		&& prm.map[(int)(prm.player_y + prm.viewx
			* lod.movespeed)][(int)prm.player_x] != '2')
		prm.player_y += prm.viewx * lod.movespeed;
	if (prm.map[(int)prm.player_y]
		[(int)(prm.player_x - prm.viewy * lod.movespeed)] != '1'
		&& prm.map[(int)prm.player_y]
			[(int)(prm.player_x - prm.viewy * lod.movespeed)] != '2')
		prm.player_x -= prm.viewy * lod.movespeed;
}
