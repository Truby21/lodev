#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <stdio.h>

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
	int 		i;

}				t_param;

#endif