/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:39:57 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 16:45:32 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	turn_left(t_data *d)
{
	d->l.olddirx = d->p.viewx;
	d->p.viewx = d->p.viewx * cos(-d->l.rotspeed) - d->p.viewy
		* sin(-d->l.rotspeed);
	d->p.viewy = d->l.olddirx * sin(-d->l.rotspeed)
		+ d->p.viewy * cos(-d->l.rotspeed);
	d->l.oldplanex = d->p.plane_x;
	d->p.plane_x = d->p.plane_x * cos(-d->l.rotspeed)
		- d->p.plane_y * sin(-d->l.rotspeed);
	d->p.plane_y = d->l.oldplanex * sin(-d->l.rotspeed)
		+ d->p.plane_y * cos(-d->l.rotspeed);
}

void	turn_right(t_data *d)
{
	d->l.olddirx = d->p.viewx;
	d->p.viewx = d->p.viewx * cos(d->l.rotspeed) - d->p.viewy
		* sin(d->l.rotspeed);
	d->p.viewy = d->l.olddirx * sin(d->l.rotspeed) + d->p.viewy
		* cos(d->l.rotspeed);
	d->l.oldplanex = d->p.plane_x;
	d->p.plane_x = d->p.plane_x * cos(d->l.rotspeed)
		- d->p.plane_y * sin(d->l.rotspeed);
	d->p.plane_y = d->l.oldplanex * sin(d->l.rotspeed)
		+ d->p.plane_y * cos(d->l.rotspeed);
}
