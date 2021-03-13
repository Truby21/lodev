/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:11:44 by truby             #+#    #+#             */
/*   Updated: 2021/03/13 22:24:59 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param 			*ft_flags(char *line, int i, t_param *param)
{
	if (line[i] == 'R')
	{
		if (line[i + 1] != ' ')
				return (ft_error("Error\nInvalid resolution.\n"));
		if (param->Rx == 0 && param->Ry == 0)
		{
			if (!(param = ft_find_xy(line, i, param)))
				return (ft_error("Error\nInvalid resolution."));
		}
		else
			return (ft_error("Error\nDouble resolution.\n"));
		param->i++;
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (line[i] == 'F')
		{
			if (line[i + 1] != ' ')
				return (ft_error("Error\nInvalid floor color.\n"));
			if (param->f_color == 0)
			{
				if ((param->f_color = ft_color(line)) == -1)
					return (ft_error("Error\nInvalid floor color.\n"));
			} else
				return (ft_error("Error\nDouble floor color.\n"));
		}
		if (line[i] == 'C')
		{
			if (line[i + 1] != ' ')
				return (ft_error("Error\nInvalid ceiling color.\n"));
			if (param->c_color == 0)
			{
				if ((param->c_color = ft_color(line)) == -1)
					return (ft_error("Error\nInvalid ceiling color.\n"));
			} else
				return (ft_error("Error\nDouble ceiling color.\n"));
			param->i++;
		}
	}
	else if (line[i] == 'N' && line[++i] == 'O')
	{
			if (line[i + 1] != ' ')
				return (ft_error("Error\nInvalid north texture.\n"));
			if (param->NO == NULL)
			{
				if (!(param->NO = ft_textures(line, i)))
					return (ft_error("Error\nInvalid north texture.\n"));
				param->i++;
			}
			else
				return (ft_error("Error\nDouble north texture.\n"));
	}
	else if (line[i] == 'S')
	{
			if (line[++i] == 'O')
			{
				if (line[i + 1] != ' ')
					return (ft_error("Error\nInvalid south texture.\n"));
				if (param->SO == NULL)
				{
					if (!(param->SO = ft_textures(line, i)))
						return (ft_error("Error\nInvalid south texture.\n"));
				}
				else
					return (ft_error("Error\nDouble south texture.\n"));
			}
			else if (line[i] == ' ')
			{
				if (param->S == NULL)
				{
					if (!(param->S = ft_textures(line, i)))
						return (ft_error("Error\nInvalid sprite texture.\n"));
				}
				else
					return (ft_error("Error\nDouble sprite texture.\n"));
			} else
				return (ft_error("Error\nInvalid config. Just like you.\n"));
			param->i++;
	}
	else if (line[i] == 'E' && line[++i] == 'A')
	{
			if (line[i + 1] != ' ')
				return (ft_error("Error\nInvalid east texture.\n"));
			if (param->EA == NULL)
			{
				if (!(param->EA = ft_textures(line, i)))
					return (ft_error("Error\nInvalid east texture.\n"));
				param->i++;
			}
			else
				return (ft_error("Error\nDouble east texture.\n"));
	}
	else if (line[i] == 'W' && line[++i] == 'E')
		{
			if (line[i + 1] != ' ')
				return (ft_error("Error\nInvalid west texture.\n"));
			if (param->WE == NULL)
			{
				if (!(param->WE = ft_textures(line, i)))
					return (ft_error("Error\nInvalid west texture.\n"));
				param->i++;
			}
			else
				return (ft_error("Error\nDouble west texture.\n"));
		}
	else
		return (ft_error("Error\nInvalid config. Just like you.\n"));
	return (param);
}
