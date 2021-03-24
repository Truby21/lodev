# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: truby <truby@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 13:54:43 by truby             #+#    #+#              #
#    Updated: 2021/03/24 14:49:13 by truby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

C_FILES = cardinal_points.c check_square.c check_begin.c check_middle.c check_end.c\
color.c draw_texture.c error.c extra_functions.c init_struct.c main.c parser.c parser_processor.c\
press_release.c rendering.c resolution.c rnd_funcs.c textures.c valid_map.c

O_FILES = $(C_FILES:.c=.o)

HEADER = cub.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILES)
	# @make -C ./libft
	# @make -C ./minilibx
	gcc -g $(O_FILES) libft.a libmlx.a -framework OpenGL -framework Appkit -o cub3D
	# gcc -g $(O_FILES) ./libft/libft.a ./minilibx/libmlx.a -framework OpenGL -framework Appkit -o cub3D

%.o: %.c $(HEADER)
	@gcc -c $<

clean:
	@rm -f $(O_FILES)
	# @make clean -C ./libft
	# @make clean -C ./minilibx

fclean: clean
	@rm -f $(NAME)
	# @make fclean -C ./libft

re: fclean all