/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:00:33 by truby             #+#    #+#             */
/*   Updated: 2021/03/17 21:45:25 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param	*valid_map(t_param *param, int maxlen, int qstr, int i)
{
	int				r;
	char			*str;

	while (param->map[++i] != NULL && qstr++ >= 0)
		maxlen = ft_max_len(param->map[i], maxlen);
	i = -1;
	while (param->map[++i] != NULL)
	{
		r = maxlen - ft_strlen_int(param->map[i]);
		str = ft_calloc_char(r, ' ');
		if (!str)
			ft_error("Error\nError of malloc.\n");
		param->map[i] = ft_strjoin_gnl(param->map[i], str);
		free(str);
	}
	i = 0;
	r = -1;
	param = ft_check_square(param, qstr - 1, maxlen - 1);
	param = ft_check_begin(param, -1);
	param = ft_check_middle(param, 0, 0);
	param = ft_check_end(param, qstr - 1, -1);
	return (param);
}
