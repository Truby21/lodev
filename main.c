/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:39:15 by truby             #+#    #+#             */
/*   Updated: 2021/03/21 22:12:29 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	first_check(int argc, char **argv, int *fd, t_param *param)
{
	int i;

	if (argc > 3)
		ft_error("Error\nToo much arguments.\n", NULL);
	if (argc < 2)
		ft_error("Error\nNeed config.\n", NULL);
	i = ft_strlen_int(argv[1]) - 1;
	if (argv[1][i] != 'b' || argv[1][i - 1] != 'u' || argv[1][i - 2] != 'c'
		|| argv[1][i - 3] != '.')
		ft_error("Error\nInvalid name of config.\n", NULL);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6))
			ft_error("Error\nUndefined flag.\n", NULL);
		else
			param->screen++;
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0)
		ft_error("Error\nCan't open this config.\n", NULL);
}

static int	last_check(t_data *data)
{
	// подсчет спрайтов добавлен в парсере
	return(0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	
	init_struct(&data);
	first_check(argc, argv, &fd, &data.param);
	ft_parser(&data.param, fd, -1);
	// ft_mymlx(&data.param, -1, -1, 0);
	data.img.mlx = mlx_init();
	last_check(&data);
	// if (!data.param.screen)
	// {
		// screensize(&data);
	data.img.win = mlx_new_window(data.img.mlx, data.param.rx, data.param.ry, "cub3D");
	// }
	mlx_hook(&data.img.mlx, 2, 0, &press, &data);
	mlx_hook(&data.img.mlx, 3, 0, &release, &data);
	mlx_hook(&data.img.mlx, 17, 0, &ft_exit, &data);
	mlx_loop_hook(data.img.mlx, &render, &data);
	mlx_loop(data.img.mlx);
	exit(0);
}
