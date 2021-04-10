/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 02:33:02 by truby             #+#    #+#             */
/*   Updated: 2021/04/10 19:26:24 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	head(t_data *data, int fd, int *num)
{
	unsigned int	sz;
	unsigned char	bmp[54];

	*num = (4 - (prm.rx * 3) % 4) % 4;
	sz = 54 + (*num + (prm.rx * 3)) * prm.ry;
	ft_memset(bmp, (unsigned char)0, 54);
	bmp[0] = 'B';
	bmp[1] = 'M';
	bmp[2] = (unsigned char)sz;
	bmp[3] = (unsigned char)(sz >> 8);
	bmp[4] = (unsigned char)(sz >> 16);
	bmp[5] = (unsigned char)(sz >> 24);
	bmp[10] = (unsigned char)54;
	bmp[14] = (unsigned char)40;
	bmp[18] = (unsigned char)(prm.rx);
	bmp[19] = (unsigned char)(prm.rx >> 8);
	bmp[20] = (unsigned char)(prm.rx >> 16);
	bmp[21] = (unsigned char)(prm.rx >> 24);
	bmp[22] = (unsigned char)(prm.ry);
	bmp[23] = (unsigned char)(prm.ry >> 8);
	bmp[24] = (unsigned char)(prm.ry >> 16);
	bmp[25] = (unsigned char)(prm.ry >> 24);
	bmp[26] = (unsigned char)1;
	bmp[28] = (unsigned char)24;
	write(fd, bmp, 54);
}

void	screenshot(t_data *data)
{
	int				fd;
	int				i;
	int				num;
	unsigned char	bmp[3];

	bmp[0] = (unsigned char)0;
	bmp[1] = (unsigned char)0;
	bmp[2] = (unsigned char)0;
	fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXU, S_IRWXG);
	head(data, fd, &num);
	while (--prm.ry >= 0)
	{
		i = -1;
		while (++i < prm.rx)
			write(fd, &((int *)im.addr)[prm.ry * prm.rx + i], 3);
		write(fd, bmp, num);
	}
	close(fd);
	ft_error(NULL, &prm);
	exit(0);
}

void	save_screen(t_data *data)
{
	if (prm.rx > 10000)
		prm.rx = 10000;
	if (prm.ry > 10000)
		prm.ry = 10000;
}

void	screensize(t_data *data)
{
	int	x;
	int	y;

	mlx_get_screen_size(im.mlx, &x, &y);
	if (prm.rx > x)
		prm.rx = x;
	if (prm.ry > y)
		prm.ry = y;
}
