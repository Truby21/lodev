/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:10:02 by truby             #+#    #+#             */
/*   Updated: 2021/03/16 15:15:27 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int					ft_spaces_and_end(char *line, int i, int fl)
{
	while (fl == 0 && !ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (-1);
	}
	while (fl == 1 && line[i] != '\0')
	{
		if (ft_isprint(line[i]) && line[i++] != ' ')
			return (-1);
	}
	return (i);
}

static int					ft_number(char *line, int i, int *r, int max)
{
	while (ft_isdigit(line[i]))
	{
		*r = *r * 10 + (line[i++] - '0');
		if (*r > max)
		{
			*r = max;
			while (ft_isdigit(line[i]))
				i++;
			break ;
		}
	}
	return (i);
}

static t_param				*ft_find_xy(char *line, int i, t_param *param)
{
	if ((i = ft_spaces_and_end(line, i, 0)) < 0 ||
	(i = ft_number(line, i, &(param->Rx), 3200)) < 0 ||
	(i = ft_spaces_and_end(line, i, 0)) < 0 ||
	(i = ft_number(line, i, &(param->Ry), 1800)) < 0 ||
	(i = ft_spaces_and_end(line, i, 1)) < 0)
		return (NULL);
	return (param);
}

t_param						*ft_res(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		return (ft_error("Error\nInvalid resolution.\n"));
	if (param->Rx == 0 && param->Ry == 0)
	{
		if (!(param = ft_find_xy(line, i, param)))
			return (ft_error("Error\nInvalid resolution.\n"));
	}
	else
		return (ft_error("Error\nDouble resolution.\n"));
	return (param);
}
