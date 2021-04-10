/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:47:23 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 01:40:28 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	press(int key, t_data *data)
{
	if (key == 0)
		ke.left = 1;
	if (key == 1)
		ke.down = 1;
	if (key == 2)
		ke.right = 1;
	if (key == 13)
		ke.up = 1;
	if (key == 124)
		ke.camright = 1;
	if (key == 123)
		ke.camleft = 1;
	if (key == 53)
	{
		ft_error(NULL, &prm);
		exit (0);
	}
	return (0);
}

int	release(int key, t_data *data)
{
	if (key == 0)
		ke.left = 0;
	if (key == 1)
		ke.down = 0;
	if (key == 2)
		ke.right = 0;
	if (key == 13)
		ke.up = 0;
	if (key == 124)
		ke.camright = 0;
	if (key == 123)
		ke.camleft = 0;
	return (0);
}

int	ft_exit(int key, t_data *data)
{
	ft_error(NULL, &prm);
	exit(0);
}
