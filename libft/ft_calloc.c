/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 01:55:47 by truby             #+#    #+#             */
/*   Updated: 2020/12/09 20:54:27 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t num, size_t size)
{
	unsigned char	*h;
	size_t			i;

	i = 0;
	h = (void *)malloc(sizeof(char) * (num * size));
	if (h == NULL)
		return (NULL);
	while (i < num * size)
	{
		h[i] = ' ';
		i++;
	}
	return (h);
}
