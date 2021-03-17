/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:58:55 by truby             #+#    #+#             */
/*   Updated: 2021/03/17 14:15:36 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_param	*ft_checkend(t_param *param, int end, int i)
{
	if (param->map[end - 1][i] != '1' && param->map[end - 1][i] != ' ')
		return (ft_error("Error\nInvalid map.\n"));
	if (param->map[end - 1][i + 1] != '1' && param->map[end - 1][i + 1] != ' ')
		return (ft_error("Error\nInvalid map.\n"));
	if (param->map[end - 1][i - 1] != '1' && param->map[end - 1][i - 1] != ' ')
		return (ft_error("Error\nInvalid map.\n"));
	return (param);
}

t_param	*ft_check_end(t_param *param, int end, int i)
{
	while (param->map[end][++i] != '\0')
	{
		if (i == 0 && param->map[end][i] == ' ' && param->map[end - 1]
		[i + 1] != '1' && param->map[end - 1][i + 1] != ' ')
			return (ft_error("Error\nInvalid map.\n"));
		else if (i != 0 && i + 1 < ft_strlen_int(param->map[end])
		&& param->map[end][i] == ' ' && !ft_checkend(param, end, i))
			return (NULL);
		else if (i + 1 == ft_strlen_int(param->map[end]) && param->map[end]
		[i] == ' ' && param->map[end - 1][i - 1] != '1' && param->map[end - 1]
		[i - 1] != ' ')
			return (ft_error("Error\nInvalid map.\n"));
		else
			continue ;
	}
	return (param);
}
