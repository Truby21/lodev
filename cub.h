/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:54:01 by truby             #+#    #+#             */
/*   Updated: 2021/03/19 15:39:09 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <stdio.h>
# include "./minilibx_opengl_20191021/mlx.h"
# include "math.h"

typedef struct	s_param
{
	int			Rx;
	int 		Ry;
	char 		*NO;
	char 		*SO;
	char 		*WE;
	char 		*EA;
	char 		*S;
	int 		f_color;
	int 		c_color;
	char 		**map;
	int 		i;
	int			fd;
	void		*mlx;
	void		*win;
	int			player;
	int			plx;
	int			ply;
}				t_param;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

void 				ft_error(char *str);
int 				ft_max_len(char *str, int k);
char				*ft_strjoin_cub(char *s1, char *s2, int i, int j);
t_param 			*ft_check_square(t_param *param, int end, int ml);
t_param 			*ft_check_begin(t_param *param, int i);
t_param 			*ft_check_middle(t_param  *param, int i, int j);
t_param 			*ft_check_end(t_param *param, int end, int i);
t_param 			*valid_map(t_param *param, int qstr, int maxlen, int i);
char 				*ft_textures(char *line, int ind, int i);
int					ft_put_square(t_data data, int x, int y);
int					ft_put_square1(t_data data, int x, int y);
int					ft_put_square_player(t_data data, int x, int y);
int 				ft_parser(t_param *param, int fd, int i, char *mapline);
t_param				*ft_parser_processor(char *line, int i, t_param *param);
t_param				*ft_res(t_param *param, char *line, int i);
t_param				*ft_col(t_param *param, char *line, int i);
t_param				*ft_no(t_param *param, char *line, int i);
t_param				*ft_so(t_param *param, char *line, int i);
t_param				*ft_s(t_param *param, char *line, int i);
t_param				*ft_ea(t_param *param, char *line, int i);
t_param				*ft_we(t_param *param, char *line, int i);
void				ft_mymlx(t_param *param, int i, int j, int x);

#endif