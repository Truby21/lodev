/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:30:46 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 01:41:40 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void init_struct(t_data *data)
{
	data->param.EA = NULL;
	data->param.WE = NULL;
	data->param.NO = NULL;
	data->param.SO = NULL;
	data->param.S = NULL;
	data->param.Ry = 0;
	data->param.Rx = 0;
	data->param.f_color = 0;
	data->param.c_color = 0;
	data->param.i = 1;
	data->param.player = 0;
	data->param.map_width = 0;
	data->param.map_height = 0;
	data->img.bits_per_pixel = 0;
	data->img.endian = 0;
	data->img.line_length = 0;
	data->img.plx = 0;
	data->img.ply = 0;
	data->img.addr = NULL;
	data->key.camleft = 0;
	data->key.camright = 0;
	data->key.up = 0;
	data->key.down = 0;
	data->key.left = 0;
	data->key.right = 0;
	return(data);
}