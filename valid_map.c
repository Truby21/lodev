/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:00:33 by truby             #+#    #+#             */
/*   Updated: 2021/03/16 18:19:24 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param				*valid_map(t_param *param, int maxlen, int qstr, int i)
{
	int				r;
	char			*str;

	while (param->map[++i] != NULL && qstr++ >= 0)
		maxlen = ft_max_len(param->map[i], maxlen);
	i = -1;
	while (param->map[++i] != NULL)
	{
		r = maxlen - ft_strlen_int(param->map[i]);
		if (!(str = ft_calloc_char(r, ' ')))
			return (ft_error("Error\nError of malloc.\n"));
		if (!(param->map[i] = ft_strjoin_gnl(param->map[i], str)))
			return (ft_error("Error\nError of malloc.\n"));
		free(str);
	}
	i = 0;
	r = -1;
	if (!(param = ft_check_square(param, qstr - 1, maxlen - 1)) ||
	!(param = ft_check_begin(param, -1)) ||
	!(param = ft_check_middle(param, 0, 0)) ||
	!(param = ft_check_end(param, qstr - 1, -1)))
		return (NULL);
	return (param);
}
