/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:47:23 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 21:46:54 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int press(int key, t_data *data)
{
	if (key == 0)
		data->key.left = 1;
	if (key == 1)
		data->key.down = 1;
	if (key == 2)
		data->key.right = 1;
	if (key == 13)
		data->key.up = 1;
	if (key == 123)
		data->key.camleft = 1;
	if (key == 124)
		data->key.camright = 1;
	if (key == 53)
		ft_error(NULL, &data->param);	
	return(0);
}

int release(int key, t_data *data)
{
	if (key == 0)
		data->key.left = 0;
	if (key == 1)
		data->key.down = 0;
	if (key == 2)
		data->key.right = 0;
	if (key == 13)
		data->key.up = 0;
	if (key == 123)
		data->key.camleft = 0;
	if (key == 124)
		data->key.camright = 0;
	return(0);
}

int	ft_exit(int key, t_data *data)
{
	ft_error(NULL, &data->param);
	return (0);
}
