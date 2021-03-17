/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:07:46 by truby             #+#    #+#             */
/*   Updated: 2021/03/16 18:03:02 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int			ft_search_str(char *line, int ind)
{
	while (line[++ind] != '\0')
	{
		if (ft_isprint(line[ind]) && line[ind] != ' ')
			break ;
	}
	if (line[ind] == '\0')
		return (-1);
	return (ind);
}

char				*ft_textures(char *line, int ind, int i)
{
	int				k;
	char			*texture;

	if ((ind = ft_search_str(line, ind)) < 0)
		return (NULL);
	k = ind;
	while (line[ind] != '\0' && ++i >= 0)
	{
		if (line[ind++] == ' ')
		{
			while (line[++ind] != '\0')
			{
				if (ft_isprint(line[ind]))
					return (NULL);
			}
			break ;
		}
	}
	if (!(texture = ft_substr(line, k, i)))
		return (ft_error3("Error\nError of malloc.\n"));
	if ((i = open(texture, O_RDONLY)) < 0)
		return (ft_error3("Error\nError of opening textures.\n"));
	else
		close(i);
	return (texture);
}
