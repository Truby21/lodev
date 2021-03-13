/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:10:02 by truby             #+#    #+#             */
/*   Updated: 2021/03/13 22:29:12 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param 				*ft_find_xy(char *line, int i, t_param *param)
{
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (NULL);
	}
	while (ft_isdigit(line[i]))
	{
		param->Rx = param->Rx * 10 + (line[i++] - '0');
		if (param->Rx > 3200)
		{
			param->Rx = 3200;
			while (ft_isdigit(line[i]))
				i++;
			break ;
		}
	}
	while (!ft_isdigit(line[i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (NULL);
		i++;
	}
	while (ft_isdigit(line[i]))
	{
		param->Ry = param->Ry * 10 + (line[i++] - '0');
		if (param->Ry > 1800)
		{
			param->Ry = 1800;
			while (ft_isdigit(line[i]))
				i++;
			break ;
		}
	}
	while (line[i] != '\0')
	{
		if (ft_isprint(line[i]) && line[i] != ' ')
			return (NULL);
		i++;
	}
	return (param->Ry == 0 || param->Rx == 0 ? NULL : param);
}
