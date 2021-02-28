/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:27:44 by truby             #+#    #+#             */
/*   Updated: 2021/02/24 00:28:22 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char 				*ft_error3(char *str)
{
	write (1, str, ft_strlen(str));
	return (NULL);
}

int 				ft_error2(char *str)
{
	write (1, str, ft_strlen(str));
	return (-1);
}

t_param 			*ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (NULL);
}
