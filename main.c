/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:39:15 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 01:43:22 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	exit(t_data *data)
{
	// ft_error() для free;
	exit(0);
}

static int	first_check(int argc, char **argv, int *fd)
{
	if (argc > 3)
		ft_error("Error\nToo much arguments.\n");
	if (argc < 2)
		ft_error("Error\nNeed config.\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nCan't open this config.\n");
	return(fd);
}

static int	last_check(t_data *data)
{
	// подсчет спрайтов добавить
	return(0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	
	init_struct(&data);
	first_check(argc, argv, &fd);
	ft_parser(&data.param, fd, -1, NULL);
	// ft_mymlx(&data.param, -1, -1, 0);
	data.param.mlx = mlx_init();
	last_check(&data);
	if (!data.param.screen)
	{
		screensize(&data);
		data.param.win = mlx_new_window(data.param.win, data.param.Rx, data.param.Ry, "cub3D");
	}
	mlx_hook(&data.param.mlx, 2, 0, &press, &data);
	mlx_hook(&data.param.mlx, 3, 0, &release, &data);
	mlx_hook(&data.param.mlx, 17, 0, &exit, &data);
	mlx_loop_hook(data.param.mlx, &render, &data);
	mlx_loop(data.param.mlx);
	exit(0);
}
