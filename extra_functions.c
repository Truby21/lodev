/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:50:21 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 18:05:13 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strjoin_cub(t_param *param, char *s2, int i, int j)
{
	char			*new;

	new = malloc(sizeof(char) * (ft_strlen_int(param->mapline) + ft_strlen_int(s2) + 2));
	if (!new)
		ft_error("Error\nError of malloc.\n", param);
	while (++i < ft_strlen_int(param->mapline))
		new[i] = param->mapline[i];
	if (param->mapline)
		new[i++] = '\n';
	while (i < ft_strlen_int(param->mapline) + ft_strlen_int(s2) + 1)
		new[i++] = s2[++j];
	new[i] = '\0';
	if (param->mapline)
		free(param->mapline);
	i = -1;
	while (new[++i] != '\0')
	{
		if (new[i] == '\n' && new[i + 1] == '\n')
			ft_error("Error\nInvalid config.\n", param);
	}
	return (new);
}

int	ft_max_len(char *str, int k)
{
	int				i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	if (i >= k)
		return (i);
	else
		return (k);
}
