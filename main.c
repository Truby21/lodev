/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:39:15 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 19:32:14 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	first_check(int argc, char **argv, int *fd, t_param *param)
{
	int		i;
	char	*buf;

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
	if (read(*fd, buf, 0) < 0)
		ft_error("Error\nCan't r this config.\n", NULL);
}

static void	sprite_textures(t_data *data, int k, int l, int sp)
{
	prm.spr = malloc(sizeof(t_spr) * (prm.qua_sprite + 1));
	if (prm.spr == NULL)
		ft_error("Error\nError of malloc.", &prm);
	while (prm.map[++k] != NULL)
	{
		while (prm.map[k][++l] != '\0')
		{
			if (prm.map[k][l] == '2')
			{
				prm.spr[++sp].y = k + 0.5;
				prm.spr[sp].x = l + 0.5;
			}
		}
		l = -1;
	}
}

static void	img_textures(t_data *data, int i)
{
	tx[0].img = mlx_xpm_file_to_image(im.mlx, prm.no,
			&tx[0].img_w, &tx[0].img_h);
	tx[1].img = mlx_xpm_file_to_image(im.mlx, prm.so,
			&tx[1].img_w, &tx[1].img_h);
	tx[2].img = mlx_xpm_file_to_image(im.mlx, prm.we,
			&tx[2].img_w, &tx[2].img_h);
	tx[3].img = mlx_xpm_file_to_image(im.mlx, prm.ea,
			&tx[3].img_w, &tx[3].img_h);
	tx[4].img = mlx_xpm_file_to_image(im.mlx, prm.sp,
			&tx[4].img_w, &tx[4].img_h);
	while (++i != 5)
	{
		if (tx[i].img == NULL)
			ft_error("Error\nOne of the textures is broken.", &prm);
	}
	tx[0].addr = mlx_get_data_addr(tx[0].img, &tx[0].bpp,
			&tx[0].len, &tx[0].end);
	tx[1].addr = mlx_get_data_addr(tx[1].img, &tx[1].bpp,
			&tx[1].len, &tx[1].end);
	tx[2].addr = mlx_get_data_addr(tx[2].img, &tx[2].bpp,
			&tx[2].len, &tx[2].end);
	tx[3].addr = mlx_get_data_addr(tx[3].img, &tx[3].bpp,
			&tx[3].len, &tx[3].end);
	tx[4].addr = mlx_get_data_addr(tx[4].img, &tx[4].bpp,
			&tx[4].len, &tx[4].end);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	init_struct(&data);
	first_check(argc, argv, &fd, &data.param);
	ft_parser(&data.param, fd, -1);
	if (data.param.qua_sprite)
		sprite_textures(&data, -1, -1, -1);
	data.img.mlx = mlx_init();
	data.img.win = mlx_new_window(data.img.mlx, dpr.rx, dpr.ry, "cub3D");
	if (!data.param.screen)
		screensize(&data);
	img_textures(&data, -1);
	mlx_hook(data.img.win, 2, 0, &press, &data);
	mlx_hook(data.img.win, 3, 0, &release, &data);
	mlx_hook(data.img.win, 17, 0, &ft_exit, &data);
	mlx_loop_hook(data.img.mlx, &render, &data);
	mlx_loop(data.img.mlx);
	exit(0);
}
