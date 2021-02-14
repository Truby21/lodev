/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 21:13:40 by truby             #+#    #+#             */
/*   Updated: 2021/02/14 20:37:19 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char 				*ft_error3(char *str)
{
	write (1, str, ft_strlen(str));
	return (NULL);
}

int 				ft_error2(char *str)
{
	write (1, str, ft_strlen(str));
	return (-1);
}

t_param 			*ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (NULL);
}

int 				ft_search_map(char *line, int g)
{
	if (line[0] == '\n')
		return (0);
	else if (line[0] == '1' || line[0] == ' ')
	{
		g = 0;
		return (1);
	}
	else
		return (-1);
}

char 				*ft_textures(char *line, int ind)
{
	int 			i;
	int 			k;
	char 			*texture;

	i = 0;
	while (line[++ind] != '\0')
	{
		if (line[ind] == ' ')
			continue ;
		if (ft_isprint(line[ind]) && line[ind] != ' ')
			break ;
	}
	if (line[ind] == '\0')
		return (ft_error3("Error\nNeed all textures."));
	k = ind;
	while (line[ind] != '\0')
	{
		if (line[ind] == ' ')
		{
			while (line[++ind] != '\0')
			{
				if (ft_isprint(line[ind]))
					return (ft_error3("Error\nExtra characters."));
			}
			break ;
		}
		ind++;
		i++;
	}
	if (!(texture = ft_substr(line, k, i)))
		return (ft_error3("Error\nError of malloc. Shit happens only with you"
					"."));
	if ((i = open(texture, O_RDONLY)) < 0)
		return (ft_error3("Error\nError of opening textures."));
	else
		close(i);
	return (texture);
}

int 				ft_color(char *line)
{
	int 			i;
	int 			R;
	int 			G;
	int 			B;

	R = 0;
	G = 0;
	B = 0;
	i = 0;
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (ft_error2(line[i] == '\0' ? "Error\nInvalid config."
									   "Please, insert all values." :
									   "Error\nExtra characters."));
	}
	while (ft_isdigit(line[i]))
		R = R * 10 + (line[i++] - '0');
	while (line[i] != ',')
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (ft_error2("Error\nInvalid config. Please insert values "
					 "correctly."));
		i++;
	}
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (ft_error2(line[i] == '\0' ? "Error\nInvalid config"
									   ".Please, insert all values." :
									   "Error\nExtra characters."));
	}
	while (ft_isdigit(line[i]))
		G = G * 10 + (line[i++] - '0');
	while (line[i] != ',')
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (ft_error2("Error\nInvalid config. Please insert values "
							  "correctly."));
		i++;
	}
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (ft_error2(line[i] == '\0' ? "Error\nInvalid config."
												"Please, insert all values." :
							  "Error\nExtra characters."));
	}
	while (ft_isdigit(line[i]))
		B = B * 10 + (line[i++] - '0');
	while (line[i] != '\0')
	{
		if (ft_isprint(line[i]) && line[i] != ' ')
			return (ft_error2("Error\nExtra characters."));
		i++;
	}
	return (0 <= R && R <= 255 && 0 <= G && G <= 255 && 0 <= B && B <= 255 ?
	 R << 16 | G << 8 | B : -1);
}

t_param 				*ft_find_xy(char *line, int i, t_param *param)
{
	while (!ft_isdigit(line[++i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (NULL);
	}
	while (ft_isdigit(line[i]))
		param->Rx = param->Rx * 10 + (line[i++] - '0');
	while (!ft_isdigit(line[i]))
	{
		if ((ft_isprint(line[i]) && line[i] != ' ') || line[i] == '\0')
			return (NULL);
		i++;
	}
	while (ft_isdigit(line[i]))
		param->Ry = param->Ry * 10 + (line[i++] - '0');
	while (line[i] != '\0')
	{
		if (ft_isprint(line[i]) && line[i] != ' ')
			return (NULL);
		i++;
	}
	return (param);
}

static t_param 			*ft_flags(char *line, int i, t_param *param)
{
	if (line[i] == 'R')
	{
		if (param->Rx == 0 && param->Ry == 0)
		{
			if (!(param = ft_find_xy(line, i, param)))
				return (ft_error("Error\nExtra characters.\n Invalid config. "
								 "Just like you."));
		}
		else
			return (ft_error("Error\nDouble resolution."));
		param->i++;
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (line[i] == 'F')
		{
			if (param->f_color == 0)
			{
				if ((param->f_color = ft_color(line)) == -1)
					return (NULL);
			} else
				return (ft_error("Error\nDouble floor color."));
		}
		if (line[i] == 'C')
		{
			if (param->c_color == 0)
			{
				if ((param->c_color = ft_color(line)) == -1)
					return (NULL);
			} else
				return (ft_error("Error\nDouble ceiling color."));
			param->i++;
		}
	}
	else if (line[i] == 'N' && line[++i] == 'O')
	{
			if (param->NO == NULL)
			{
				if (!(param->NO = ft_textures(line, i)))
					return (NULL);
				param->i++;
			}
			else
				return (ft_error("Error\nDouble north texture."));
	}
	else if (line[i] == 'S')
	{
			if (line[++i] == 'O')
			{
				if (param->SO == NULL)
				{
					if (!(param->SO = ft_textures(line, i)))
						return (NULL);
				}
				else
					return (ft_error("Error\nDouble south texture."));
			}
			else if (line[i] == ' ')
			{
				if (param->S == NULL)
				{
					if (!(param->S = ft_textures(line, i)))
						return (NULL);
				}
				else
					return (ft_error("Error\nDouble sprite texture."));
			} else
				return (ft_error("Error\nInvalid config. Just like you."));
			param->i++;
	}
	else if (line[i] == 'E' && line[++i] == 'A')
	{
			if (param->EA == NULL)
			{
				if (!(param->EA = ft_textures(line, i)))
					return (NULL);
				param->i++;
			}
			else
				return (ft_error("Error\nDouble east texture."));
	}
	else if (line[i] == 'W' && line[++i] == 'E')
		{
			if (param->WE == NULL)
			{
				if (!(param->WE = ft_textures(line, i)))
					return (NULL);
				param->i++;
			}
			else
				return (ft_error("Error\nDouble west texture."));
		}
	else
		return (ft_error("Error\nInvalid config. Just like you."));
	return (param);
}

int main(int argc, char **argv)
{
	int fd;
	char *line;
//	char 		**map;
	int i;
	int gnl;
	t_param *param;
	int b;

	if (argc != 2)
		return (ft_error2(argc > 2 ? "Error\nToo much arguments." :
						  "Error\nNeed config."));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error2("Error\nCan't open this config."));
	line = NULL;
	i = -1;
	b = 0;
	if (!(param = (t_param *) malloc(sizeof(t_param))))
		return (ft_error2("Error\nError of malloc. Shit happens only with you"
						  "."));
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
		while (line[++i] != '\0' && param->i != 8)
		{
			if (line[i] > 64 && line[i] < 91)
			{
				if (!(param = ft_flags(line, i, param)))
					return (-1);
				else
					break;
			} else if (line[i] == ' ')
				continue;
			else
				return (ft_error2("Error\nExtra characters.\nInvalid config. "
								  "Just like you."));
		}
		if (param->i == 8)
		{

		}
		free(line);
		i = -1;
	}
	free(line);
	if ((gnl == 0 && param->i != 9) || gnl == -1)
		return (ft_error2(gnl == 0 && param->i != 9 ? "Error\nNeed correct "
											   "config." :
						  "Error\nCan't read this config."));
	//if(!(map = ft_split()))
	//	return (ft_error2("Error\nError of malloc. Shit happens only with you"
	//						  "."));
	return (0);
}
















//	i = -1;
//	g = 0;
//	while((gnl = get_next_line(fd, &line)))
//	{
//		if (ft_search_map(line, g))
//		{
//			map[++i] = ft_strdup(line);
//			g++;
//		}
//		else
//		{
//			if (g > 0)
//				return (ft_error(5));
//			else
//				continue;
//		}
//		free(line);
//	}
//	while (map[++i])
//	{
//		write(1, map[i], ft_strlen(map[i]));
//		write(1, "\n", 1);
//	}
//}