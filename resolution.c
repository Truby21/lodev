/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:10:02 by truby             #+#    #+#             */
/*   Updated: 2021/04/14 22:12:32 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_spaces_and_end(char *line, int *i, int fl)
{
	while (fl == 0 && !ft_isdigit(line[++(*i)]))
	{
		if ((ft_isprint(line[*i]) && line[*i] != ' ') || line[*i] == '\0')
			return (-1);
	}
	while (fl == 1 && line[*i] != '\0')
	{
		if (ft_isprint(line[*i]) && line[(*i)++] != ' ')
			return (-1);
	}
	return (1);
}

static int	ft_number(char *line, int *i, int *r)
{
	while (ft_isdigit(line[*i]))
	{
		*r = *r * 10 + (line[(*i)++] - '0');
		if (*r > MAX_RES)
		{
			*r = MAX_RES;
			while (ft_isdigit(line[*i]) && line[*i] != '\0')
				(*i)++;
			break ;
		}
	}
	return (1);
}

static t_param	*ft_find_xy(char *line, int i, t_param *param)
{
	if (ft_spaces_and_end(line, &i, 0) < 0
		|| (ft_number(line, &i, &(param->rx))) < 0
		|| (ft_spaces_and_end(line, &i, 0)) < 0
		|| (ft_number(line, &i, &(param->ry))) < 0
		|| (ft_spaces_and_end(line, &i, 1)) < 0)
		ft_error("Error\nInvalid resolution.\n", param);
	else if (param->rx == 0 || param->ry == 0)
		ft_error("Error\nInvalid resolution.\n", param);
	return (param);
}

t_param	*ft_res(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid resolution.\n", param);
	if (param->rx == 0 && param->ry == 0)
		ft_find_xy(line, i, param);
	else
		ft_error("Error\nDouble resolution.\n", param);
	return (param);
}
