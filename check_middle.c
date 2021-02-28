/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_middle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:57:42 by truby             #+#    #+#             */
/*   Updated: 2021/02/24 00:58:08 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_param 				*ft_check_middle(t_param  *param, int maxlen, int end)
{
	int 				i;
	int 				j;
	int 				fl;

	i = 0;
	j = 0;
	fl = 0;
	(void)end;
	(void)maxlen;
	while (++i && param->map[i + 1] != NULL)
	{
		while(param->map[i][++j] != '\0' )
		{
			if (param->map[i][j] == ' ')
			{
				if (param->map[i - 1][j - 1] != '1' && param->map[i - 1][j -
				1] != ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i - 1][j] != '1' && param->map[i - 1][j]
				!= ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i - 1][j + 1] != '1' && param->map[i - 1][j + 1]
				!= ' ' && param->map[i - 1][j + 1] != '\0')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i][j - 1] != '1' && param->map[i][j - 1] != ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i][j + 1] != '1' && param->map[i][j + 1] !=
				' ' && param->map[i][j + 1] != '\0')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i + 1][j - 1] != '1' && param->map[i + 1][j - 1]
				!= ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i + 1][j] != '1' && param->map[i + 1][j] !=
				' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i + 1][j + 1] != '1' && param->map[i + 1][j + 1]
				!= ' ' && param->map[i + 1][j + 1] != '\0')
					return (ft_error("Error\nInvalid map.\n"));
			}
			else if (param->map[i][j] == '0' || param->map[i][j] == '2'
			||param->map[i][j] == 'N' || param->map[i][j] == 'S' ||
			param->map[i][j] == 'E' || param->map[i][j] == 'W')
			{
				if (param->map[i - 1][j - 1] == ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i - 1][j] == ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i - 1][j + 1] == ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i][j - 1] == ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i][j + 1] == ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i + 1][j - 1] == ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i + 1][j] == ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (param->map[i + 1][j + 1] == ' ')
					return (ft_error("Error\nInvalid map.\n"));
				if (ft_isalpha(param->map[i][j]))
				{
					fl++;
					if (fl > 1)
						return (ft_error("Error\nDouble player.\n"));
				}
			}
			else if (param->map[i][j] == '1')
				continue ;
			else
				return (ft_error("Error\nInvalid map.\n"));
		}
		j = 0;
	}
	if (fl == 0)
		return(ft_error("Error\nNeed player.\n"));
	return (param);
}