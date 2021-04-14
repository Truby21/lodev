/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepside.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:12:19 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 16:44:59 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	step_side_x(t_data *d, double first, double second)
{
	d->l.stepx = first;
	d->l.sidedistx = second;
}

void	step_side_y(t_data *d, double first, double second)
{
	d->l.stepy = first;
	d->l.sidedisty = second;
}
