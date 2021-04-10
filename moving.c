/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:08:47 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 17:17:56 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	moving(t_data *data)
{
	lod.frametime = (lod.time - lod.oldtime) / 1000.0;
	lod.movespeed = lod.frametime * 5.0;
	lod.rotspeed = lod.frametime * 1.5;
	if (data->key.up)
		move_forward(data);
	if (data->key.down)
		move_backward(data);
	if (data->key.right)
		move_right(data);
	if (data->key.left)
		move_left(data);
	if (data->key.camleft)
		turn_left(data);
	if (data->key.camright)
		turn_right(data);
}
