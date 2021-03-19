/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:07:46 by truby             #+#    #+#             */
/*   Updated: 2021/03/19 15:36:17 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_search_str(char *line, int *ind, int *k)
{
	while (line[++(*ind)] != '\0')
	{
		if (ft_isprint(line[*ind]) && line[*ind] != ' ')
			break ;
	}
	if (line[*ind] == '\0')
		return (-1);
	*k = *ind;
	return (1);
}

char	*ft_textures(char *line, int ind, int i)
{
	int				k;
	char			*texture;

	if ((ft_search_str(line, &ind, &k)) < 0)
		return (NULL);
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
	texture = ft_substr(line, k, i);
	if (!texture)
		ft_error("Error\nError of malloc.\n");
	if ((open(texture, O_RDONLY)) < 0)
		ft_error("Error\nError of opening texture.\n");
	else
		close(i);
	return (texture);
}
