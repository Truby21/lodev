/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:00:33 by truby             #+#    #+#             */
/*   Updated: 2021/02/24 01:00:59 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param 				*ft_valid_map(t_param *param)
{

	int 			i;
	int 			qstr;
	int 			maxlen;
	int 			r;
	char 			*str;

	i = -1;
	qstr = 0;
	maxlen = 0;
	while (param->map[++i] != NULL)
	{
		maxlen = ft_max_len(param->map[i], maxlen);
		qstr++;
	}
	i = -1;
	while (param->map[++i] != NULL)
	{
		r = maxlen - ft_strlen_int(param->map[i]);
		if (!(str = ft_calloc_char(r, ' ')))
			return (ft_error("Error\nError of malloc. Shit happens only with"
							 " you.\n"));
		if (!(param->map[i] = ft_strjoin_gnl(param->map[i], str)))
			return (ft_error("Error\nError of malloc. Shit happens only with"
							 " you.\n"));
		free(str);
	}
	i = 0;
	r = -1;
	if (!(param = ft_check_square(param, qstr - 1, maxlen - 1)))
		return (NULL);
	if (!(param = ft_check_begin(param)))
		return (NULL);
	if (!(param = ft_check_middle(param, maxlen, qstr)))
		return (NULL);
	if (!(param = ft_check_end(param, qstr - 1)))
		return (NULL);
	return (param);
}