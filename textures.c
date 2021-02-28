/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:07:46 by truby             #+#    #+#             */
/*   Updated: 2021/02/24 01:08:12 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char 				*ft_textures(char *line, int ind)
{
	int 			i;
	int 			k;
	char 			*texture;

	i = 0;
	while (line[++ind] != '\0')
	{
		if (line[ind] == ' ')
			continue ;
		if (ft_isprint(line[ind]) && line[ind] != ' ')
			break ;
	}
	if (line[ind] == '\0')
		return (ft_error3("Error\nNeed all textures.\n"));
	k = ind;
	while (line[ind] != '\0')
	{
		if (line[ind] == ' ')
		{
			while (line[++ind] != '\0')
			{
				if (ft_isprint(line[ind]))
					return (ft_error3("Error\nExtra characters.\n"));
			}
			break ;
		}
		ind++;
		i++;
	}
	if (!(texture = ft_substr(line, k, i)))
		return (ft_error3("Error\nError of malloc. Shit happens only with you"
					".\n"));
	if ((i = open(texture, O_RDONLY)) < 0)
		return (ft_error3("Error\nError of opening textures.\n"));
	else
		close(i);
	return (texture);
}