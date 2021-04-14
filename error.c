/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:27:44 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 16:52:58 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	clear_param(t_param *param, int i)
{
	if (param->no != NULL)
		free(param->no);
	if (param->so != NULL)
		free(param->so);
	if (param->ea != NULL)
		free(param->ea);
	if (param->we != NULL)
		free(param->we);
	if (param->sp != NULL)
		free(param->sp);
	if (param->mapline != NULL)
		free(param->mapline);
	if (param->spr != NULL)
		free(param->spr);
	if (param->map != NULL)
	{
		while (param->map[++i] != NULL)
			free(param->map[i]);
		free(param->map);
	}
}

void	ft_error(char *str, t_param *param)
{
	if (param != NULL)
		clear_param(param, -1);
	if (str != NULL)
		write(1, str, ft_strlen(str));
	else
		return ;
	exit(0);
}
