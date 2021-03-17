/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:11:53 by truby             #+#    #+#             */
/*   Updated: 2021/03/17 19:46:03 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param	*ft_no(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid north texture.\n");
	if (param->NO == NULL)
	{	
		param->NO = ft_textures(line, i, 0);
		if (!param->NO)
			ft_error("Error\nInvalid north texture.\n");
	}
	else
		ft_error("Error\nDouble north texture.\n");
	return (param);
}

t_param	*ft_so(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid south texture.\n");
	if (param->SO == NULL)
	{
		param->SO = ft_textures(line, i, 0);
		if (!param->SO)
			ft_error("Error\nInvalid south texture.\n");
	}
	else
		ft_error("Error\nDouble south texture.\n");
	return (param);
}

t_param	*ft_ea(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid east texture.\n");
	if (param->EA == NULL)
	{
		param->EA = ft_textures(line, i, 0);
		if (!param->EA)
			ft_error("Error\nInvalid east texture.\n");
	}
	else
		ft_error("Error\nDouble east texture.\n");
	return (param);
}

t_param	*ft_we(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid west texture.\n");
	if (param->WE == NULL)
	{
		param->WE = ft_textures(line, i, 0);
		if (!param->WE)
			ft_error("Error\nInvalid west texture.\n");
	}
	else
		ft_error("Error\nDouble west texture.\n");
	return (param);
}

t_param	*ft_s(t_param *param, char *line, int i)
{
	if (param->S == NULL)
	{
		param->S = ft_textures(line, i, 0);
		if (!param->S)
			ft_error("Error\nInvalid sprite texture.\n");
	}
	else
		ft_error("Error\nDouble sprite texture.\n");
	return (param);
}
