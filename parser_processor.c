/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:46:56 by truby             #+#    #+#             */
/*   Updated: 2021/03/15 21:32:33 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param				*ft_parser_processor(char *line, int i, t_param *param)
{
	if (line[i] == 'R' && param->i++)
		param = ft_res(param, line, i);
	else if ((line[i] == 'F' || line[i] == 'C') && param->i++)
		param = ft_col(param, line, i);
	else if (line[i] == 'N' && line[++i] == 'O' && param->i++)
		param = ft_no(param, line, i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && param->i++)
		param = ft_so(param, line, ++i);
	else if (line[i] == 'S' && line[i + 1] == ' ' && param->i++)
		param = ft_s(param, line, ++i);
	else if (line[i] == 'E' && line[++i] == 'A' && param->i++)
		param = ft_ea(param, line, i);
	else if (line[i] == 'W' && line[++i] == 'E')
		param = ft_we(param, line, i);
	else
		return (ft_error("Error\nInvalid config.\n"));
	return (param);
}
