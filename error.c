/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:27:44 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 18:19:16 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	clear_param(t_param *param, int i)
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
	write(1, str, ft_strlen(str));
	exit(0);
}
