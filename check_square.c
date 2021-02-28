/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:54:51 by truby             #+#    #+#             */
/*   Updated: 2021/02/24 00:55:17 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param 				*ft_check_square(t_param *param, int end, int maxlen)
{
	int 				i;

	i = -1;
	while (param->map[0][++i] != '\0')
	{
		if (ft_isprint(param->map[0][i]) && param->map[0][i] != '1' &&
			param->map[0][i] != ' ')
			return (ft_error("Error\nInvalid map."));
	}
	i = -1;
	while (param->map[end][++i] != '\0')
	{
		if (ft_isprint(param->map[end][i]) && param->map[end][i] != '1' &&
			param->map[end][i] != ' ')
			return (ft_error("Error\nInvalid map."));
	}
	i = -1;
	while (++i < end)
	{
		if (ft_isprint(param->map[i][0]) && param->map[i][0] != '1' &&
			param->map[i][0] != ' ')
			return (ft_error("Error\nInvalid map."));
	}
	i = -1;
	while (++i < end)
	{
		if (ft_isprint(param->map[i][maxlen]) && param->map[i][maxlen] !=
		'1' && param->map[i][maxlen] != ' ')
			return (ft_error("Error\nInvalid map."));
	}
	return (param);
}