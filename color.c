/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 01:08:35 by truby             #+#    #+#             */
/*   Updated: 2021/02/24 01:08:54 by truby            ###   ########.fr       */
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
			return (ft_error2(line[i] == '\0' ? "Error\nInvalid config."
									   "Please, insert all values.\n" :
									   "Error\nExtra characters.\n"));
	}
	while (ft_isdigit(line[i]))
		R = R * 10 + (line[i++] - '0');
	while (line[i] != ',')
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (ft_error2("Error\nInvalid config. Please insert values "
					 "correctly.\n"));
		i++;
	}
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (ft_error2(line[i] == '\0' ? "Error\nInvalid config"
									   ".Please, insert all values.\n" :
									   "Error\nExtra characters.\n"));
	}
	while (ft_isdigit(line[i]))
		G = G * 10 + (line[i++] - '0');
	while (line[i] != ',')
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (ft_error2("Error\nInvalid config. Please insert values "
							  "correctly.\n"));
		i++;
	}
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (ft_error2(line[i] == '\0' ? "Error\nInvalid config."
												"Please, insert all values.\n" :
							  "Error\nExtra characters.\n"));
	}
	while (ft_isdigit(line[i]))
		B = B * 10 + (line[i++] - '0');
	while (line[i] != '\0')
	{
		if (ft_isprint(line[i]) && line[i] != ' ')
			return (ft_error2("Error\nExtra characters.\n"));
		i++;
	}
	return (0 <= R && R <= 255 && 0 <= G && G <= 255 && 0 <= B && B <= 255 ?
	 R << 16 | G << 8 | B : -1);
}