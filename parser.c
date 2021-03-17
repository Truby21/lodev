/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:13:40 by truby             #+#    #+#             */
/*   Updated: 2021/03/16 21:10:58 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_param			*check_and_spl(t_param *param, int gnl, char *mapline)
{
	if ((gnl == 0 && param->i <= 8) || gnl == -1)
	{
		free(param);
		free(mapline);
		return (ft_error(gnl == 0 && param->i <= 8 ? "Error\nNeed correct "
		"config.\n" : "Error\nCan't read this config.\n"));
	}
	if (!(param->map = ft_split(mapline, '\n')))
	{
		free(param);
		free(mapline);
		return (ft_error("Error\nError of malloc.\n"));
	}
	free(mapline);
	return (param);
}

static t_param			*ft_map(t_param *param, char *line, char **mapline)
{
	if (param->i == 8)
	{
		param->i++;
		return (param);
	}
	if (param->i >= 9)
	{
		if (ft_strchr(line, '1') || ft_strchr(line, ' '))
		{
			if (!(*mapline = ft_strjoin_cub(*mapline, line)))
				return (ft_error("Error\nError of malloc.\n"));
			param->i++;
		}
		else
		{
			if (param->i > 9)
				return (ft_error("Error\nInvalid map.\n"));
		}
	}
	return (param);
}

static t_param			*ft_search_letter(char *line, t_param *param, int *i)
{
	while (line[++(*i)] != '\0' && param->i < 8)
	{
		if (line[*i] > 64 && line[*i] < 91)
		{
			if (!(param = ft_parser_processor(line, *i, param)))
				return (NULL);
			else
				break ;
		}
		else if (line[*i] == ' ')
		{
			if (line[(*i) + 1] == '\0')
				return (ft_error("Error\nInvalid config.\n"));
			else
				continue ;
		}
		else
		{
			free(param);
			free(line);
			return (ft_error("Error\nInvalid config.\n"));
		}
	}
	*i = -1;
	return (param);
}

int						ft_parser(t_param *param, int fd, int i)
{
	char				*line;
	int					gnl;
	char				*mapline;

	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (!(param = ft_search_letter(line, param, &i)))
			return (-1);
		if (param->i >= 8)
			if (!(param = ft_map(param, line, &mapline)))
				return (-1);
		free(line);
	}
	if (!(mapline = ft_strjoin_cub(mapline, line)))
		return (ft_error2("Error\nError of malloc.\n"));
	free(line);
	if (!(param = check_and_spl(param, gnl, mapline)))
		return (-1);
	if (!(param = valid_map(param, 0, 0, -1)))
		return (-1);
	ft_mymlx(param, -1, -1, 0);
	return (1);
}
