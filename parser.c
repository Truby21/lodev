/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:13:40 by truby             #+#    #+#             */
/*   Updated: 2021/04/18 18:04:48 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_and_spl(t_param *param, int gnl, char *line)
{
	if (gnl == 0 && param->i <= 9)
		ft_error("Error\nNeed correct config.\n", param);
	if (gnl == -1)
		ft_error("Error\nCan't read this config.\n", param);
	param->mapline = ft_strjoin_cub(param, line, -1, -1);
	free(line);
	param->map = ft_split(param->mapline, '\n');
	if (!param->map)
		ft_error("Error\nError of malloc.\n", param);
	free(param->mapline);
	param->mapline = NULL;
}

static void	ft_map(t_param *param, char *line)
{
	if (param->i == 8 && param->i++)
		return ;
	if (param->i >= 9)
	{
		if ((ft_strchr(line, '1') || ft_strchr(line, ' ')) && param->i++)
			param->mapline = ft_strjoin_cub(param, line, -1, -1);
		else if (param->i == 9 && (ft_strchr(line, '2') || ft_strchr(line, '0')
				|| ft_strchr(line, 'N') || ft_strchr(line, 'S')
				|| ft_strchr(line, 'E') || ft_strchr(line, 'W')))
		{
			ft_error("Error\nInvalid map.\n", param);
		}
		else
		{
			if (param->i > 9)
				ft_error("Error\nInvalid config.\n", param);
		}
	}
}

static void	ft_search_letter(char *line, t_param *param, int *i)
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
}

void	ft_parser(t_param *param, int fd, int i)
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
	check_and_spl(param, gnl, line);
	valid_map(param, -1);
}
