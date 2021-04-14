/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 02:33:02 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 21:06:27 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	head(t_data *d, int fd, int *num)
{
	unsigned int	sz;
	unsigned char	bmp[54];

	*num = (4 - (d->p.rx * 3) % 4) % 4;
	sz = 54 + (*num + (d->p.rx * 3)) * d->p.ry;
	ft_memset(bmp, (unsigned char)0, 54);
	bmp[0] = 'B';
	bmp[1] = 'M';
	bmp[2] = (unsigned char)sz;
	bmp[3] = (unsigned char)(sz >> 8);
	bmp[4] = (unsigned char)(sz >> 16);
	bmp[5] = (unsigned char)(sz >> 24);
	bmp[10] = (unsigned char)54;
	bmp[14] = (unsigned char)40;
	bmp[18] = (unsigned char)(d->p.rx);
	bmp[19] = (unsigned char)(d->p.rx >> 8);
	bmp[20] = (unsigned char)(d->p.rx >> 16);
	bmp[21] = (unsigned char)(d->p.rx >> 24);
	bmp[22] = (unsigned char)(d->p.ry);
	bmp[23] = (unsigned char)(d->p.ry >> 8);
	bmp[24] = (unsigned char)(d->p.ry >> 16);
	bmp[25] = (unsigned char)(d->p.ry >> 24);
	bmp[26] = (unsigned char)1;
	bmp[28] = (unsigned char)24;
	write(fd, bmp, 54);
}

void	screenshot(t_data *d)
{
	int				fd;
	int				i;
	int				num;
	unsigned char	bmp[3];

	bmp[0] = (unsigned char)0;
	bmp[1] = (unsigned char)0;
	bmp[2] = (unsigned char)0;
	fd = open("screen.bmp", O_RDWR | O_CREAT, S_IRWXU, S_IRWXG);
	head(d, fd, &num);
	while (--d->p.ry >= 0)
	{
		i = -1;
		while (++i < d->p.rx)
			write(fd, &((int *)d->i.addr)[d->p.ry * d->p.rx + i], 3);
		write(fd, bmp, num);
	}
	close(fd);
	ft_error(NULL, &d->p);
	exit(0);
}

void	screensize(t_data *d)
{
	int	x;
	int	y;

	if (!d->p.screen)
	{
		mlx_get_screen_size(d->i.mlx, &x, &y);
		if (d->p.rx > x)
			d->p.rx = x;
		if (d->p.ry > y)
			d->p.ry = y;
	}
	else
	{
		if (d->p.rx > MAX_SCREEN)
			d->p.rx = MAX_SCREEN;
		if (d->p.ry > MAX_SCREEN)
			d->p.ry = MAX_SCREEN;
	}
}
