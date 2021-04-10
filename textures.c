/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:07:46 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 01:58:45 by truby            ###   ########.fr       */
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

char	*ft_textures(t_param *param, char *line, int ind, int i)
{
	int				k;
	char			*texture;
	char			*buff;

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
	if (!texture || (open(texture, O_RDWR) == -1))
		ft_error("Error\nError of textures.\n", param);
	close(i);
	return (texture);
}
