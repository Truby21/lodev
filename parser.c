/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:13:40 by truby             #+#    #+#             */
/*   Updated: 2021/03/13 22:17:25 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main(int argc, char **argv)
{
	int fd;
	char *line;
	int i;
	int gnl;
	t_param *param;
	char *mapline;
	void *mlx;
	void *win;
	int	x;
	int	y = 0;
	int j = -1;


	if (argc != 2)
		return (ft_error2(argc > 2 ? "Error\nToo much arguments.\n" :
						  "Error\nNeed config.\n"));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error2("Error\nCan't open this config.\n"));
	line = NULL;
	i = -1;
	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (ft_error2("Error\nError of malloc. Shit happens only with you"
						  ".\n"));
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
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		while (line[++i] != '\0' && param->i < 8 )
		{
			if (line[i] > 64 && line[i] < 91)
			{
				if (!(param = ft_flags(line, i, param)))
					return (-1);
				else
					break ;
			}
			else if (line[i] == ' ')
			{
				if (line[i + 1] == '\0')
					return(ft_error2("Error\nInvalid config.\n"));
				else
					continue ;
			}
			else
				return (ft_error2("Error\nExtra characters.\nInvalid config. "
								  "Just like you.\n"));
		}
		if (param->i == 8)
		{
			param->i++;
			continue;
		}
		if (param->i >= 9)
		{
			if (ft_strchr(line, '1') || ft_strchr(line, ' '))
			{
				if (!(mapline = ft_strjoin_cub(mapline, line)))
					return (-1);
				param->i++;
			}
			else
			{
				if (param->i > 9)
					return (ft_error2("Error\nInvalid map.\n"));
			}
		}
		free(line);
		i = -1;
	}
	if (!(mapline = ft_strjoin_cub(mapline, line)))
		return (ft_error2("Error\nError of malloc. Shit happens only "
					"with you.\n"));
	free(line);
	if ((gnl == 0 && param->i < 8) || gnl == -1)
		return (ft_error2(gnl == 0 && param->i != 9 ? "Error\nNeed correct "
											   "config.\n" :
						  "Error\nCan't read this config.\n"));
	if (!(param->map = ft_split(mapline, '\n')))
		return (ft_error2("Error\nError of malloc. Shit happens only with "
					"you.\n"));
	if (!(param = ft_valid_map(param)))
		return (-1);
//	printf("%s", mapline);
//	printf("%s\n", param->NO);
//	printf("%s\n", param->SO);
//	printf("%s\n", param->WE);
//	printf("%s\n", param->EA);
//	printf("%s\n", param->S);
//	printf("%i\n", param->Rx);
//	printf("%i\n", param->Ry);
//	printf("%x\n", param->f_color);
//	printf("%x\n", param->c_color);
//	i = 0;
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i++]);
//	printf("%s\n", param->map[i]);
	i = -1;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1080, 720, "2D");
	while (param->map[++i] != NULL)
	{
		y = y + 30;
		x = 0;
		while (param->map[i][++j] != '\0')
		{
			x = x + 30;
			if (param->map[i][j] == '1')
				ft_put_square(mlx, win, x, y);
			else if (param->map[i][j] == '0')
				ft_put_square1(mlx, win, x, y);
			else if (param->map[i][j] == 'N')
				ft_put_square_player(mlx, win, x, y);
			else
				continue ;
		}
		j = -1;
	}
	mlx_loop(mlx);
}
