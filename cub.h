/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truby <truby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:54:01 by truby             #+#    #+#             */
/*   Updated: 2021/04/12 21:11:38 by truby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <stdio.h>
# include "./minilib_static/mlx.h"
# include "./minilib_dynamic/mlx2.h"
# include "math.h"

# define MAX_SCREEN 10000
# define MAX_RES 30000

typedef struct s_spr
{
	double			x;
	double			y;
	double			distance;
}					t_spr;

typedef struct s_param
{
	int				rx;
	int				ry;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
	char			*mapline;
	int				f_color;
	int				c_color;
	char			**map;
	int				i;
	int				fl_player;
	double			player_x;
	double			player_y;
	double			viewx;
	double			viewy;
	double			plane_x;
	double			plane_y;
	int				screen;
	int				map_width;
	int				map_height;
	int				qua_sprite;
	t_spr			*spr;
}					t_param;

typedef struct s_key
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				esc;
	int				camright;
	int				camleft;
}					t_key;

typedef struct s_img
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				bpp;
	int				length;
	int				end;
}					t_img;

typedef struct s_txtr
{
	void			*img;
	void			*addr;
	int				bpp;
	int				len;
	int				img_w;
	int				img_h;
	int				end;
}					t_txtr;

typedef struct s_lod
{
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				drawstart;
	int				drawend;
	int				texx;
	int				texy;
	unsigned int	*color;
	double			time;
	double			oldtime;
	double			frametime;
	double			movespeed;
	double			rotspeed;
	double			camx;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perp;
	double			lineheight;
	double			wallx;
	double			step;
	double			texpos;
	double			olddirx;
	double			oldplanex;
}					t_lod;

typedef struct s_sp
{
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	double			*zb;
	int				sprite_screen_x;
	int				v_move_screen;
	int				sprite_height;
	int				sprite_width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				stripe;
	int				texx;
	int				texy;
	int				y;
	int				d;
	unsigned int	*color;
}					t_sp;

typedef struct s_data
{
	t_param			p;
	t_img			i;
	t_txtr			t[6];
	t_key			k;
	t_lod			l;
	t_sp			s;
}					t_data;

void				ft_error(char *str, t_param *param);
int					ft_max_len(char *str, int k);
char				*ft_strjoin_cub(t_param *param, char *s2, int i, int j);
t_param				*ft_check_square(t_param *param, int end, int ml);
t_param				*ft_check_begin(t_param *param, int i);
t_param				*ft_check_middle(t_param *param, int i, int j);
t_param				*ft_check_end(t_param *param, int end, int i);
t_param				*valid_map(t_param *param, int i);
char				*ft_textures(t_param *param, char *line, int ind, int i);
void				ft_parser(t_param *param, int fd, int i);
t_param				*ft_parser_processor(char *line, int i, t_param *param);
t_param				*ft_res(t_param *param, char *line, int i);
t_param				*ft_col(t_param *param, char *line, int i);
t_param				*ft_no(t_param *param, char *line, int i);
t_param				*ft_so(t_param *param, char *line, int i);
t_param				*ft_s(t_param *param, char *line, int i);
t_param				*ft_ea(t_param *param, char *line, int i);
t_param				*ft_we(t_param *param, char *line, int i);
void				init_struct(t_data *d);
int					press(int key, t_data *d);
int					release(int key, t_data *d);
int					render(t_data *d);
void				screensize(t_data *d);
void				save_screen(t_data *d);
void				pixel_put(t_data *d, int x, int y, int color);
unsigned int		*pixel_take(t_txtr *txtr, int texty, int textx);
void				draw_floor_ceiling(t_data *d, int x, int y);
void				draw_texture(t_data *d, int x, int y);
int					ft_exit(int key, t_data *d);
void				sort_spr(t_data *d);
void				draw_sprite(t_data *d, int i);
void				moving(t_data *d);
double				deltadist(double rayone, double raytwo);
void				screenshot(t_data *d);
void				turn_left(t_data *d);
void				turn_right(t_data *d);
void				move_forward(t_data *d);
void				move_backward(t_data *d);
void				move_left(t_data *d);
void				move_right(t_data *d);
void				screensize(t_data *d);
void				init_five(t_data *d);
void				step_side_y(t_data *d, double first, double second);
void				step_side_x(t_data *d, double first, double second);
void				clear_param(t_param *param, int i);

#endif