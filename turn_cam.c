/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:39:57 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 13:50:06 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	turn_left(t_data *data)
{
	lod.olddirx = prm.viewx;
	prm.viewx = prm.viewx * cos(-lod.rotspeed) - prm.viewy * sin(-lod.rotspeed);
	prm.viewy = lod.olddirx * sin(-lod.rotspeed)
		+ prm.viewy * cos(-lod.rotspeed);
	lod.oldplanex = prm.plane_x;
	prm.plane_x = prm.plane_x * cos(-lod.rotspeed)
		- prm.plane_y * sin(-lod.rotspeed);
	prm.plane_y = lod.oldplanex * sin(-lod.rotspeed)
		+ prm.plane_y * cos(-lod.rotspeed);
}

void	turn_right(t_data *data)
{
	lod.olddirx = prm.viewx;
	prm.viewx = prm.viewx * cos(lod.rotspeed) - prm.viewy * sin(lod.rotspeed);
	prm.viewy = lod.olddirx * sin(lod.rotspeed) + prm.viewy * cos(lod.rotspeed);
	lod.oldplanex = prm.plane_x;
	prm.plane_x = prm.plane_x * cos(lod.rotspeed)
		- prm.plane_y * sin(lod.rotspeed);
	prm.plane_y = lod.oldplanex * sin(lod.rotspeed)
		+ prm.plane_y * cos(lod.rotspeed);
}
