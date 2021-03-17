/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:50:21 by truby             #+#    #+#             */
/*   Updated: 2021/03/16 18:14:40 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char				*ft_strjoin_cub(char *s1, char *s2)
{
	char			*new;
	int				i;
	int				j;

	i = -1;
	j = -1;
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2))))
		return (ft_error3("Error\nError of malloc.\n"));
	while (++i < ft_strlen_int(s1))
		new[i] = s1[i];
	if (s1)
		new[i++] = '\n';
	while (i < ft_strlen_int(s1) + ft_strlen_int(s2) + 1)
		new[i++] = s2[++j];
	new[i] = '\0';
	if (s1)
		free(s1);
	i = -1;
	while (new[++i] != '\0')
	{
		if (new[i] == '\n' && new[i + 1] == '\n')
			return (ft_error3("Error\nInvalid config.\n"));
	}
	return (new);
}

int					ft_max_len(char *str, int k)
{
	int				i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i >= k ? i : k);
}
