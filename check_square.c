/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:54:51 by truby             #+#    #+#             */
/*   Updated: 2021/03/17 22:20:46 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_param	*ft_check_first_line(t_param *param, int i)
{
	while (param->map[0][++i] != '\0')
	{
		if (ft_isprint(param->map[0][i]) && param->map[0][i] != '1'
			&& param->map[0][i] != ' ')
			ft_error("Error\nInvalid map.\n");
	}
	return (param);
}

static t_param	*ft_check_last_line(t_param *param, int end, int i)
{
	while (param->map[end][++i] != '\0')
	{
		if (ft_isprint(param->map[end][i]) && param->map[end][i] != '1'
			&& param->map[end][i] != ' ')
			ft_error("Error\nInvalid map.\n");
	}
	return (param);
}

static t_param	*ft_check_left_line(t_param *param, int end, int i)
{
	while (++i < end)
	{
		if (ft_isprint(param->map[i][0]) && param->map[i][0] != '1'
			&& param->map[i][0] != ' ')
			ft_error("Error\nInvalid map.\n");
	}
	return (param);
}

static t_param	*ft_check_right_line(t_param *param, int end, int ml)
{
	int	i;

	i = -1;
	while (++i < end)
	{
		if (ft_isprint(param->map[i][ml]) && param->map[i][ml] != '1'
			&& param->map[i][ml] != ' ')
			ft_error("Error\nInvalid map.\n");
	}
	return (param);
}

t_param	*ft_check_square(t_param *param, int end, int ml)
{
	ft_check_first_line(param, -1);
	ft_check_last_line(param, end, -1);
	ft_check_left_line(param, end, -1);
	ft_check_right_line(param, end, ml);
	return (param);
}
