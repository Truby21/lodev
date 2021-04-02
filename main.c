/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:39:15 by truby             #+#    #+#             */
/*   Updated: 2021/04/02 17:07:14 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	first_check(int argc, char **argv, int *fd, t_param *param)
{
	int i;
	char *buf;

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

static void	img_textures(t_data *dt)
{
	// dt->txtr[0].img = mlx_xpm_file_to_image(dt->img.mlx, dt->param.sp, &dt->txtr[0].img_w, &dt->txtr[0].img_h);
	// dt->txtr[0].addr = mlx_get_data_addr(dt->txtr[0].img, &dt->txtr[0].bpp, &dt->txtr[0].len, &dt->txtr[0].end);
	dt->txtr[1].img = mlx_xpm_file_to_image(dt->img.mlx, dt->param.no, &dt->txtr[1].img_w, &dt->txtr[1].img_h);
	dt->txtr[1].addr = mlx_get_data_addr(dt->txtr[1].img, &dt->txtr[1].bpp, &dt->txtr[1].len, &dt->txtr[1].end);
	dt->txtr[2].img = mlx_xpm_file_to_image(dt->img.mlx, dt->param.so, &dt->txtr[2].img_w, &dt->txtr[2].img_h);
	dt->txtr[2].addr = mlx_get_data_addr(dt->txtr[2].img, &dt->txtr[2].bpp, &dt->txtr[2].len, &dt->txtr[2].end);
	dt->txtr[3].img = mlx_xpm_file_to_image(dt->img.mlx, dt->param.we, &dt->txtr[3].img_w, &dt->txtr[3].img_h);
	dt->txtr[3].addr = mlx_get_data_addr(dt->txtr[3].img, &dt->txtr[3].bpp, &dt->txtr[3].len, &dt->txtr[3].end);
	dt->txtr[4].img = mlx_xpm_file_to_image(dt->img.mlx, dt->param.ea, &dt->txtr[4].img_w, &dt->txtr[4].img_h);
	dt->txtr[4].addr = mlx_get_data_addr(dt->txtr[4].img, &dt->txtr[4].bpp, &dt->txtr[4].len, &dt->txtr[4].end);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	int		i;
	
	i = -1;
	init_struct(&data);
	first_check(argc, argv, &fd, &data.param);
	ft_parser(&data.param, fd, -1);
	data.img.mlx = mlx_init();
	data.img.win = mlx_new_window(data.img.mlx, data.param.rx, data.param.ry, "cub3D");
	img_textures(&data);
	// data.img.img = mlx_new_image(data.img.win, data.param.rx, data.param.ry);
	// data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
//	if (!data.param.screen)
	{
		// screensize(&data);
		// data.img.win = mlx_new_window(data.img.mlx, data.param.rx, data.param.ry, "cub3D");
	}
	mlx_hook(data.img.win, 2, 0, &press, &data);
	mlx_hook(data.img.win, 3, 0, &release, &data);
	mlx_hook(data.img.win, 17, 0, &ft_exit, &data);
	mlx_loop_hook(data.img.mlx, &render, &data);
	mlx_loop(data.img.mlx);
	exit(0);
}
