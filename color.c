/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:08:35 by truby             #+#    #+#             */
/*   Updated: 2021/03/13 22:36:47 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int 				ft_color(char *line)
{
	int 			i;
	int 			R;
	int 			G;
	int 			B;

	R = 0;
	G = 0;
	B = 0;
	i = 0;
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (-1);
	}
	while (ft_isdigit(line[i]))
	{
		R = R * 10 + (line[i++] - '0');
		if (R > 255)
			return (-1);
	}
	while (line[i] != ',')
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (-1);
		i++;
	}
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (-1);
	}
	while (ft_isdigit(line[i]))
	{
		G = G * 10 + (line[i++] - '0');
		if (G > 255)
			return (-1);
	}
	while (line[i] != ',')
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (-1);
		i++;
	}
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (-1);
	}
	while (ft_isdigit(line[i]))
	{
		B = B * 10 + (line[i++] - '0');
		if (B > 255)
			return (-1);
	}
	while (line[i] != '\0')
	{
		if (ft_isprint(line[i]) && line[i] != ' ')
			return (-1);
		i++;
	}
	return (0 <= R && R <= 255 && 0 <= G && G <= 255 && 0 <= B && B <= 255 ?
	 R << 16 | G << 8 | B : -1);
}