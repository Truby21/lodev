/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:54:01 by truby             #+#    #+#             */
/*   Updated: 2021/03/30 19:33:56 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <stdio.h>
# include "./minilibx/mlx.h"
# include "math.h"

typedef struct	s_param
{
	int			rx;
	int 		ry;
	char 		*no;
	char 		*so;
	char 		*we;
	char 		*ea;
	char 		*sp;
	char		*mapline;
	int 		f_color;
	int 		c_color;
	char 		**map;
	int 		i;
	int			fl_player;
	double		player_x;
	double		player_y;
	double		viewx;
	double		viewy;
	double		plane_x;
	double		plane_y;
	int			screen;
	int			map_width;
	int			map_height;
	int			qua_sprite;
}				t_param;

typedef	struct s_key
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			esc;
	int			camright;
	int			camleft;
}				t_key;

typedef	struct	s_img
{
	void		*mlx;
	void		*win;
	void        *img;
    void        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}				t_img;

// typedef struct	s_sprite
// {
	
// }				t_sprite;

typedef struct  s_data 
{
	t_img		img;
	t_key		key;
	t_param		param;
	// t_sprite	sprite;
}               t_data;


void				ft_error(char *str, t_param *param);
int 				ft_max_len(char *str, int k);
char				*ft_strjoin_cub(t_param *param, char *s2, int i, int j);
t_param 			*ft_check_square(t_param *param, int end, int ml);
t_param 			*ft_check_begin(t_param *param, int i);
t_param 			*ft_check_middle(t_param  *param, int i, int j);
t_param 			*ft_check_end(t_param *param, int end, int i);
t_param 			*valid_map(t_param *param, int i);
char 				*ft_textures(t_param *param, char *line, int ind, int i);
// int					ft_put_square(t_data *data, int x, int y);
// int					ft_put_square1(t_data *data, int x, int y);
// int					ft_put_square_player(t_data *data, int x, int y);
void 				ft_parser(t_param *param, int fd, int i);
t_param				*ft_parser_processor(char *line, int i, t_param *param);
t_param				*ft_res(t_param *param, char *line, int i);
t_param				*ft_col(t_param *param, char *line, int i);
t_param				*ft_no(t_param *param, char *line, int i);
t_param				*ft_so(t_param *param, char *line, int i);
t_param				*ft_s(t_param *param, char *line, int i);
t_param				*ft_ea(t_param *param, char *line, int i);
t_param				*ft_we(t_param *param, char *line, int i);
void				ft_mymlx(t_param *param, int i, int j, int x);
void				init_struct(t_data *data);
int					press(int key, t_data *data);
int					release(int key, t_data *data);
int					render(t_data *data);
void				screensize(t_data *data);
void				save_screen(t_data *data);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				draw_floor_ceiling(t_data *data, int x, int y);
void				draw_texture(t_data *data);
int					ft_exit(int key, t_data *data);

#endif