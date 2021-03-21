/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:13:40 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 18:03:13 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_param	*check_and_spl(t_param *param, int gnl)
{
	if (gnl == 0 && param->i <= 8)
		ft_error("Error\nNeed correct config.\n", param);
	if (gnl == -1)
		ft_error("Error\nCan't read this config.\n", param);
	param->map = ft_split(param->mapline, '\n');
	if (!param->map)
		ft_error("Error\nError of malloc.\n", param);
	free(param->mapline);
	param->mapline = NULL;
	return (param);
}

static t_param	*ft_map(t_param *param, char *line)
{
	if (param->i == 8 && param->i++)
		return (param);
	if (param->i >= 9)
	{
		if ((ft_strchr(line, '1') || ft_strchr(line, ' ')) && param->i++)
			param->mapline = ft_strjoin_cub(param, line, -1, -1);
		else
		{
			if (param->i > 9)
				ft_error("Error\nInvalid map.\n", param);
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
			ft_parser_processor(line, *i, param);
			break ;
		}
		else if (line[*i] == ' ')
		{
			if (line[(*i) + 1] == '\0')
				ft_error("Error\nInvalid config.\n", param);
			else
				continue ;
		}
		else
			ft_error("Error\nInvalid config.\n", param);
	}
	*i = -1;
	return (param);
}

int	ft_parser(t_param *param, int fd, int i)
{
	char				*line;
	int					gnl;

	line = NULL;
	gnl = get_next_line(fd, &line);
	while (gnl > 0)
	{
		ft_search_letter(line, param, &i);
		ft_map(param, line);
		free(line);
		gnl = get_next_line(fd, &line);
	}
	param->mapline = ft_strjoin_cub(param, line, -1, -1);
	free(line);
	check_and_spl(param, gnl);
	valid_map(param, -1);
	return (1);
}
