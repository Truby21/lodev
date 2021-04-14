/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:39:15 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 21:05:20 by truby            ###   ########.fr       */
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

static void	sprite_textures(t_data *d, int k, int l, int sp)
{
	d->p.spr = malloc(sizeof(t_spr) * (d->p.qua_sprite + 1));
	if (d->p.spr == NULL)
		ft_error("Error\nError of malloc.", &d->p);
	while (d->p.map[++k] != NULL)
	{
		while (d->p.map[k][++l] != '\0')
		{
			if (d->p.map[k][l] == '2')
			{
				d->p.spr[++sp].y = k + 0.5;
				d->p.spr[sp].x = l + 0.5;
			}
		}
		l = -1;
	}
}

static void	img_textures(t_data *d, int i)
{
	d->t[0].img = mlx_xpm_file_to_image(d->i.mlx, d->p.no,
			&d->t[0].img_w, &d->t[0].img_h);
	d->t[1].img = mlx_xpm_file_to_image(d->i.mlx, d->p.so,
			&d->t[1].img_w, &d->t[1].img_h);
	d->t[2].img = mlx_xpm_file_to_image(d->i.mlx, d->p.we,
			&d->t[2].img_w, &d->t[2].img_h);
	d->t[3].img = mlx_xpm_file_to_image(d->i.mlx, d->p.ea,
			&d->t[3].img_w, &d->t[3].img_h);
	d->t[4].img = mlx_xpm_file_to_image(d->i.mlx, d->p.sp,
			&d->t[4].img_w, &d->t[4].img_h);
	while (++i != 5)
	{
		if (d->t[i].img == NULL)
			ft_error("Error\nOne of the textures is broken.", &d->p);
	}
	d->t[0].addr = mlx_get_data_addr(d->t[0].img, &d->t[0].bpp,
			&d->t[0].len, &d->t[0].end);
	d->t[1].addr = mlx_get_data_addr(d->t[1].img, &d->t[1].bpp,
			&d->t[1].len, &d->t[1].end);
	d->t[2].addr = mlx_get_data_addr(d->t[2].img, &d->t[2].bpp,
			&d->t[2].len, &d->t[2].end);
	d->t[3].addr = mlx_get_data_addr(d->t[3].img, &d->t[3].bpp,
			&d->t[3].len, &d->t[3].end);
	d->t[4].addr = mlx_get_data_addr(d->t[4].img, &d->t[4].bpp,
			&d->t[4].len, &d->t[4].end);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	init_struct(&data);
	first_check(argc, argv, &fd, &data.p);
	ft_parser(&data.p, fd, -1);
	if (data.p.qua_sprite)
		sprite_textures(&data, -1, -1, -1);
	data.i.mlx = mlx_init();
	screensize(&data);
	data.i.win = mlx_new_window(data.i.mlx, data.p.rx, data.p.ry, "cub3D");
	img_textures(&data, -1);
	if (data.p.screen)
		render(&data);
	mlx_hook(data.i.win, 2, 0, &press, &data);
	mlx_hook(data.i.win, 3, 0, &release, &data);
	mlx_hook(data.i.win, 17, 0, &ft_exit, &data);
	mlx_loop_hook(data.i.mlx, &render, &data);
	mlx_loop(data.i.mlx);
	exit(0);
}
