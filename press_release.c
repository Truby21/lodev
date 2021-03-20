/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:47:23 by truby             #+#    #+#             */
/*   Updated: 2021/03/20 23:28:22 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int press(int key, t_data *data)
{
	// printf("key:%d", key);
	if (key == 1)
		data->key.left = 1;
	return(0);
}

int release(int key, t_data *data)
{
	if (key == 1)
		data->key.left = 0;
	return(0);
}
