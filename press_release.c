/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:47:23 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 18:20:44 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	press(int key, t_data *d)
{
	if (key == 0)
		d->k.left = 1;
	if (key == 1)
		d->k.down = 1;
	if (key == 2)
		d->k.right = 1;
	if (key == 13)
		d->k.up = 1;
	if (key == 124)
		d->k.camright = 1;
	if (key == 123)
		d->k.camleft = 1;
	if (key == 53)
	{
		ft_error(NULL, &d->p);
		exit (0);
	}
	return (0);
}

int	release(int key, t_data *d)
{
	if (key == 0)
		d->k.left = 0;
	if (key == 1)
		d->k.down = 0;
	if (key == 2)
		d->k.right = 0;
	if (key == 13)
		d->k.up = 0;
	if (key == 124)
		d->k.camright = 0;
	if (key == 123)
		d->k.camleft = 0;
	return (0);
}

int	ft_exit(int key, t_data *d)
{
	exit(0);
}
