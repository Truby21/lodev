/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_begin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:56:21 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 17:55:19 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_param	*ft_checkbegin(t_param *param, int i)
{
	if (param->map[1][i] != '1' && param->map[1][i] != ' ')
		ft_error("Error\nInvalid map.\n", param);
	if (param->map[1][i + 1] != '1' && param->map[1][i + 1] != ' ')
		ft_error("Error\nInvalid map.\n", param);
	if (param->map[1][i - 1] != '1' && param->map[1][i - 1] != ' ')
		ft_error("Error\nInvalid map.\n", param);
	return (param);
}

t_param	*ft_check_begin(t_param *param, int i)
{
	while (param->map[0][++i] != '\0')
	{
		if (i == 0 && param->map[0][i] == ' ' && param->map[1][i + 1] != '1'
			&& param->map[1][i + 1] != ' ')
			ft_error("Error\nInvalid map.\n", param);
		else if (i != 0 && i + 1 < ft_strlen_int(param->map[0])
			&& param->map[0][i] == ' ')
			ft_checkbegin(param, i);
		else if (i + 1 == ft_strlen_int(param->map[0]) && param->map[0][i]
			== ' ' && param->map[1][i - 1] != '1'
			&& param->map[1][i - 1] != ' ')
			ft_error("Error\nInvalid map.\n", param);
		else
			continue ;
	}
	return (param);
}
