/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:24:08 by truby             #+#    #+#             */
/*   Updated: 2021/01/30 23:08:45 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_clear(char *rem)
{
	if (rem)
		free(rem);
	return (-1);
}

int					get_next_line(int fd, char **line)
{
	static char		*rem;
	char			buff[BUFFER_SIZE + 1];
	int				qua;

	qua = 1;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || fd < 0 || !line)
		return (-1);
	while (!ft_strchr_n(rem) && qua != 0)
	{
		qua = read(fd, buff, BUFFER_SIZE);
		buff[qua] = '\0';
		if (!(rem = ft_strjoin_gnl(rem, buff)))
			return (ft_clear(rem));
	}
	if (!(*line = ft_strdup_line(rem)))
		return (ft_clear(rem));
	if (!(rem = ft_strdup_rem(rem)) && ft_strchr_n(rem))
		return (ft_clear(rem));
	return (qua ? 1 : 0);
}
