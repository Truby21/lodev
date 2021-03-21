/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:58:55 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 17:56:27 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_param	*ft_checkend(t_param *param, int end, int i)
{
	if (param->map[end - 1][i] != '1' && param->map[end - 1][i] != ' ')
		ft_error("Error\nInvalid map.\n", param);
	if (param->map[end - 1][i + 1] != '1' && param->map[end - 1][i + 1] != ' ')
		ft_error("Error\nInvalid map.\n", param);
	if (param->map[end - 1][i - 1] != '1' && param->map[end - 1][i - 1] != ' ')
		ft_error("Error\nInvalid map.\n", param);
	return (param);
}

t_param	*ft_check_end(t_param *param, int end, int i)
{
	while (param->map[end][++i] != '\0')
	{
		if (i == 0 && param->map[end][i] == ' ' && param->map[end - 1]
			[i + 1] != '1' && param->map[end - 1][i + 1] != ' ')
			ft_error("Error\nInvalid map.\n", param);
		else if (i != 0 && i + 1 < ft_strlen_int(param->map[end])
			&& param->map[end][i] == ' ')
			ft_checkend(param, end, i);
		else if (i + 1 == ft_strlen_int(param->map[end]) && param->map[end]
			[i] == ' ' && param->map[end - 1][i - 1] != '1' && param->map
			[end - 1][i - 1] != ' ')
			ft_error("Error\nInvalid map.\n", param);
		else
			continue ;
	}
	return (param);
}
