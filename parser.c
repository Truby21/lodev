/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:13:40 by truby             #+#    #+#             */
/*   Updated: 2021/03/19 15:39:59 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_param	*check_and_spl(t_param *param, int gnl, char *mapline)
{
	if (gnl == 0 && param->i <= 8)
		ft_error("Error\nNeed correct config.\n");
	if (gnl == -1)
		ft_error("Error\nCan't read this config.\n");
	param->map = ft_split(mapline, '\n');
	if (!param->map)
		ft_error("Error\nError of malloc.\n");
	free(mapline);
	return (param);
}

static t_param	*ft_map(t_param *param, char *line, char **mapline)
{
	if (param->i == 8 && param->i++)
		return (param);
	if (param->i >= 9)
	{
		if ((ft_strchr(line, '1') || ft_strchr(line, ' ')) && param->i++)
			*mapline = ft_strjoin_cub(*mapline, line, -1, -1);
		else
		{
			if (param->i > 9)
				ft_error("Error\nInvalid map.\n");
		}
	}
	return (param);
}

static t_param	*ft_search_letter(char *line, t_param *param, int *i)
{
	while (line[++(*i)] != '\0' && param->i < 8)
	{
		if (line[*i] > 64 && line[*i] < 91)
		{
			param = ft_parser_processor(line, *i, param);
			break ;
		}
		else if (line[*i] == ' ')
		{
			if (line[(*i) + 1] == '\0')
				ft_error("Error\nInvalid config.\n");
			else
				continue ;
		}
		else
			ft_error("Error\nInvalid config.\n");
	}
	*i = -1;
	return (param);
}

int	ft_parser(t_param *param, int fd, int i, char *mapline)
{
	char				*line;
	int					gnl;

	line = NULL;
	gnl = get_next_line(fd, &line);
	while (gnl > 0)
	{
		param = ft_search_letter(line, param, &i);
		param = ft_map(param, line, &mapline);
		free(line);
		gnl = get_next_line(fd, &line);
	}
	mapline = ft_strjoin_cub(mapline, line, -1, -1);
	free(line);
	param = check_and_spl(param, gnl, mapline);
	param = valid_map(param, 0, 0, -1);
	ft_mymlx(param, -1, -1, 0);
	return (1);
}
