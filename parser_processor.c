/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_processor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:46:56 by truby             #+#    #+#             */
/*   Updated: 2021/03/19 15:59:21 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param	*ft_parser_processor(char *line, int i, t_param *param)
{
	if (line[i] == 'R' && param->i++)
		ft_res(param, line, i);
	else if ((line[i] == 'F' || line[i] == 'C') && param->i++)
		ft_col(param, line, i);
	else if (line[i] == 'N' && line[++i] == 'O' && param->i++)
		ft_no(param, line, i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && param->i++)
		ft_so(param, line, ++i);
	else if (line[i] == 'S' && line[i + 1] == ' ' && param->i++)
		ft_s(param, line, ++i);
	else if (line[i] == 'E' && line[++i] == 'A' && param->i++)
		ft_ea(param, line, i);
	else if (line[i] == 'W' && line[++i] == 'E')
		ft_we(param, line, i);
	else
		ft_error("Error\nInvalid config.\n");
	return (param);
}
