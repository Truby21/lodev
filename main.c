/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:39:15 by truby             #+#    #+#             */
/*   Updated: 2021/03/16 17:58:48 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char **argv)
{
	t_param *param;
	int		fd;

	if (argc != 2)
	{
		return (ft_error2(argc > 2 ? "Error\nToo much arguments.\n" :
		"Error\nNeed config.\n"));
	}
	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (ft_error2("Error\nError of malloc.\n"));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error2("Error\nCan't open this config.\n"));
	param->EA = NULL;
	param->WE = NULL;
	param->NO = NULL;
	param->SO = NULL;
	param->S = NULL;
	param->Ry = 0;
	param->Rx = 0;
	param->f_color = 0;
	param->c_color = 0;
	param->i = 1;
	param->player = 0;
	return (ft_parser(param, fd, -1));
}
