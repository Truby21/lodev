#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <stdio.h>
# include "./minilibx_opengl_20191021/mlx.h"

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

}				t_param;

char 				*ft_error3(char *str);
int 				ft_error2(char *str);
t_param 			*ft_error(char *str);
int 				ft_max_len(char *str, int k);
char				*ft_strjoin_cub(char *s1, char *s2);
t_param 			*ft_check_square(t_param *param, int end, int maxlen);
t_param 			*ft_check_begin(t_param *param);
t_param 			*ft_check_middle(t_param  *param, int maxlen, int end);
t_param 			*ft_check_end(t_param *param, int end);
t_param 			*ft_valid_map(t_param *param);
char 				*ft_textures(char *line, int ind);
int 				ft_color(char *line);
t_param 			*ft_find_xy(char *line, int i, t_param *param);
t_param 			*ft_flags(char *line, int i, t_param *param);
int					ft_put_square(void *mlx, void *win, int x, int y);
int					ft_put_square1(void *mlx, void *win, int x, int y);
int					ft_put_square_player(void *mlx, void *win, int x, int y);

#endif