/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:08:35 by truby             #+#    #+#             */
/*   Updated: 2021/03/15 21:50:03 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int				ft_spaces(char *line, int *i)
{
	while (!ft_isdigit(line[++(*i)]))
	{
		if ((ft_isprint(line[*i]) && line[*i] != ' ') || line[*i] == '\0')
			return (-1);
	}
	return (*i);
}

static int				ft_number(char *line, int i, int *rgb)
{
	while (ft_isdigit(line[i]))
	{
		*rgb = (*rgb) * 10 + (line[i++] - '0');
		if (*rgb > 255)
			return (-1);
	}
	return (i);
}

static int				ft_comma_and_end(char *ln, int *i, int fl)
{
	if (fl == 1)
	{
		while (ln[*i] != ',')
		{
			if ((ft_isprint(ln[*i]) && ln[*i] != ' ') || ln[(*i)++] == '\0')
				return (-1);
		}
	}
	else
	{
		while (ln[*i] != '\0')
		{
			if (ft_isprint(ln[*i]) && ln[(*i)++] != ' ')
				return (-1);
		}
	}
	return (*i);
}

static int				ft_color(char *line, int r, int g, int i)
{
	int					b;

	b = 0;
	if ((ft_spaces(line, &i)) < 0 || (i = ft_number(line, i, &r)) < 0 ||
	(ft_comma_and_end(line, &i, 1)) < 0)
		return (-1);
	if ((ft_spaces(line, &i)) < 0 || (i = ft_number(line, i, &g)) < 0 ||
	(ft_comma_and_end(line, &i, 1)) < 0)
		return (-1);
	if ((ft_spaces(line, &i)) < 0 || (i = ft_number(line, i, &b)) < 0 ||
	(ft_comma_and_end(line, &i, 0)) < 0)
		return (-1);
	return (0 < r && 0 < g && 0 <= b ? r << 16 | g << 8 | b : -1);
}

t_param					*ft_col(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		return (ft_error("Error\nInvalid color.\n"));
	if (line[i] == 'F')
	{
		if (param->f_color == 0)
		{
			if ((param->f_color = ft_color(line, 0, 0, i)) == -1)
				return (ft_error("Error\nInvalid floor color.\n"));
		}
		else
			return (ft_error("Error\nDouble floor color.\n"));
	}
	if (line[i] == 'C')
	{
		if (param->c_color == 0)
		{
			if ((param->c_color = ft_color(line, 0, 0, i)) == -1)
				return (ft_error("Error\nInvalid ceiling color.\n"));
		}
		else
			return (ft_error("Error\nDouble ceiling color.\n"));
	}
	return (param);
}
