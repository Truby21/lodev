/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:08:35 by truby             #+#    #+#             */
/*   Updated: 2021/03/17 22:21:05 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_spaces(char *line, int *i)
{
	while (!ft_isdigit(line[++(*i)]))
	{
		if ((ft_isprint(line[*i]) && line[*i] != ' ') || line[*i] == '\0')
			return (-1);
	}
	return (1);
}

static int	ft_number(char *line, int *i, int *rgb)
{
	while (ft_isdigit(line[*i]))
	{
		*rgb = (*rgb) * 10 + (line[(*i)++] - '0');
		if (*rgb > 255)
			return (-1);
	}
	if (rgb <= 0)
		return (-1);
	return (1);
}

static int	ft_comma_and_end(char *ln, int *i, int fl)
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
	return (1);
}

static int	ft_color(char *line, int r, int g, int i)
{
	int					b;

	b = 0;
	if ((ft_spaces(line, &i)) < 0 || (ft_number(line, &i, &r)) < 0
		|| (ft_comma_and_end(line, &i, 1)) < 0)
		return (-1);
	if ((ft_spaces(line, &i)) < 0 || (ft_number(line, &i, &g)) < 0
		|| (ft_comma_and_end(line, &i, 1)) < 0)
		return (-1);
	if ((ft_spaces(line, &i)) < 0 || (ft_number(line, &i, &b)) < 0
		|| (ft_comma_and_end(line, &i, 0)) < 0)
		return (-1);
	return (r << 16 | g << 8 | b);
}

t_param	*ft_col(t_param *param, char *line, int i)
{
	if (line[i + 1] != ' ')
		ft_error("Error\nInvalid color.\n");
	if (line[i] == 'F')
	{
		if (param->f_color == 0)
		{
			param->f_color = ft_color(line, 0, 0, i);
			if (param->f_color == -1)
				ft_error("Error\nInvalid floor color.\n");
		}
		else
			ft_error("Error\nDouble floor color.\n");
	}
	if (line[i] == 'C')
	{
		if (param->c_color == 0)
		{
			param->c_color = ft_color(line, 0, 0, i);
			if (param->c_color == -1)
				ft_error("Error\nInvalid ceiling color.\n");
		}
		else
			ft_error("Error\nDouble ceiling color.\n");
	}
	return (param);
}
