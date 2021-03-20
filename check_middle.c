/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_middle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:57:42 by truby             #+#    #+#             */
/*   Updated: 2021/03/20 21:51:39 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_param	*ft_check_space(t_param *param, int i, int j)
{
	if (param->map[i - 1][j - 1] != '1' && param->map[i - 1][j - 1] != ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i - 1][j] != '1' && param->map[i - 1][j] != ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i - 1][j + 1] != '1' && param->map[i - 1][j + 1] != ' '
		&& param->map[i - 1][j + 1] != '\0')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i][j - 1] != '1' && param->map[i][j - 1] != ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i][j + 1] != '1' && param->map[i][j + 1] != ' '
		&& param->map[i][j + 1] != '\0')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i + 1][j - 1] != '1' && param->map[i + 1][j - 1] != ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i + 1][j] != '1' && param->map[i + 1][j] != ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i + 1][j + 1] != '1' && param->map[i + 1][j + 1] != ' '
		&& param->map[i + 1][j + 1] != '\0')
		ft_error("Error\nInvalid map.\n");
	return (param);
}

static t_param	*ft_check_zero(t_param *param, int i, int j)
{
	if (param->map[i - 1][j - 1] == ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i - 1][j] == ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i - 1][j + 1] == ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i][j - 1] == ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i][j + 1] == ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i + 1][j - 1] == ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i + 1][j] == ' ')
		ft_error("Error\nInvalid map.\n");
	if (param->map[i + 1][j + 1] == ' ')
		ft_error("Error\nInvalid map.\n");
	if (ft_isalpha(param->map[i][j]))
	{
		param->player++;
		if (param->player > 1)
			ft_error("Error\nDouble player.\n");
	}
	return (param);
}

t_param	*ft_check_middle(t_param *param, int i, int j)
{
	while (++i && param->map[i + 1] != NULL)
	{
		while (param->map[i][++j] != '\0')
		{
			if (param->map[i][j] == ' ')
				ft_check_space(param, i, j);
			else if (param->map[i][j] == '0' || param->map[i][j] == '2'
				|| param->map[i][j] == 'N' || param->map[i][j] == 'S'
				||param->map[i][j] == 'E' || param->map[i][j] == 'W')
				ft_check_zero(param, i, j);
			else if (param->map[i][j] == '1')
				continue ;
			else
				ft_error("Error\nInvalid map.\n");
		}
		j = 0;
	}
	if (param->player == 0)
		ft_error("Error\nNeed player.\n");
	return (param);
}
