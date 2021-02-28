/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_begin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:56:21 by truby             #+#    #+#             */
/*   Updated: 2021/02/24 00:56:49 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param 				*ft_check_begin(t_param *param)
{
	int 				i;

	i = -1;
	while (param->map[0][++i] != '\0')
	{
		if ( i == 0 && param->map[0][i] == ' ')
		{
			if (param->map[1][i + 1] != '1' && param->map[1][i + 1] != ' ')
				return (ft_error("Error\nInvalid map."));
		}
		else if ( i != 0 && i + 1 < ft_strlen_int(param->map[0]) &&
		param->map[0][i] == ' ')
		{
			if (param->map[1][i] != '1' && param->map[1][i] != ' ')
				return (ft_error("Error\nInvalid map."));
			if (param->map[1][i + 1] != '1' && param->map[1][i + 1] != ' ')
				return (ft_error("Error\nInvalid map."));
			if (param->map[1][i - 1] != '1' && param->map[1][i - 1] != ' ')
				return (ft_error("Error\nInvalid map."));
		}
		else if ( i + 1 == ft_strlen_int(param->map[0]) && param->map[0][i]
		== ' ')
		{
			if (param->map[1][i - 1] != '1' && param->map[1][i - 1] != ' ')
				return (ft_error("Error\nInvalid map."));
		}
		else
			continue;
	}
	return (param);
}