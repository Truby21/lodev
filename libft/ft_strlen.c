/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:47:39 by truby             #+#    #+#             */
/*   Updated: 2020/12/04 20:15:30 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *str)
{
	size_t		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}
