/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:11:53 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 20:32:29 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param	*ft_no(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid north texture.\n", param);
	if (param->no == NULL)
	{	
		param->no = ft_textures(param, line, i, 0);
		if (!param->no)
			ft_error("Error\nInvalid north texture.\n", param);
	}
	else
		ft_error("Error\nDouble north texture.\n", param);
	return (param);
}

t_param	*ft_so(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid south texture.\n", param);
	if (param->so == NULL)
	{
		param->so = ft_textures(param, line, i, 0);
		if (!param->so)
			ft_error("Error\nInvalid south texture.\n", param);
	}
	else
		ft_error("Error\nDouble south texture.\n", param);
	return (param);
}

t_param	*ft_ea(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid east texture.\n", param);
	if (param->ea == NULL)
	{
		param->ea = ft_textures(param, line, i, 0);
		if (!param->ea)
			ft_error("Error\nInvalid east texture.\n", param);
	}
	else
		ft_error("Error\nDouble east texture.\n", param);
	return (param);
}

t_param	*ft_we(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid west texture.\n", param);
	if (param->we == NULL)
	{
		param->we = ft_textures(param, line, i, 0);
		if (!param->we)
			ft_error("Error\nInvalid west texture.\n", param);
	}
	else
		ft_error("Error\nDouble west texture.\n", param);
	return (param);
}

t_param	*ft_s(t_param *param, char *line, int i)
{
	if (param->sp == NULL)
	{
		param->sp = ft_textures(param, line, i, 0);
		if (!param->sp)
			ft_error("Error\nInvalid sprite texture.\n", param);
	}
	else
		ft_error("Error\nDouble sprite texture.\n", param);
	return (param);
}
