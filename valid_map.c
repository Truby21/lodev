/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:00:33 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 17:54:33 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param	*valid_map(t_param *param, int i)
{
	int				r;
	char			*str;

	while (param->map[++i] != NULL && param->map_height++ >= 0)
		param->map_width = ft_max_len(param->map[i], param->map_width);
	i = -1;
	while (param->map[++i] != NULL)
	{
		r = param->map_width - ft_strlen_int(param->map[i]);
		str = ft_calloc_char(r, ' ');
		if (!str)
			ft_error("Error\nError of malloc.\n", param);
		param->map[i] = ft_strjoin_gnl(param->map[i], str);
		free(str);
	}
	i = 0;
	r = -1;
	ft_check_square(param, param->map_height - 1, param->map_width - 1);
	ft_check_begin(param, -1);
	ft_check_middle(param, 0, 0);
	ft_check_end(param, param->map_height - 1, -1);
	return (param);
}
