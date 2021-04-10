# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: truby <truby@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 13:54:43 by truby             #+#    #+#              #
#    Updated: 2021/04/10 19:03:58 by truby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

C_FILES = cardinal_points.c check_square.c check_begin.c check_middle.c check_end.c\
color.c draw_texture.c error.c extra_functions.c init_struct.c main.c parser.c parser_processor.c\
press_release.c rendering.c resolution.c draw.c textures.c valid_map.c funcs.c moving.c\
draw_sprite.c screenshot.c keys.c turn_cam.c

O_FILES = $(C_FILES:.c=.o)

HEADER = cub.h

.PHONY: all clean fclean re

bonus: re

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C ./libft
	@make -C ./minilib_static
	@make -C ./minilib_dynamic
	gcc -g $(O_FILES) libft.a ./minilib_static/libmlx.a ./minilib_dynamic/libmlx.dylib -framework OpenGL -framework Appkit -o cub3D
	# gcc -g $(O_FILES) ./libft/libft.a ./minilib_static/libmlx.a ./minilib_dynamic/libmlx.dylib -framework OpenGL -framework Appkit -o cub3D

%.o: %.c $(HEADER)
	@gcc -c $<

clean:
	@rm -f $(O_FILES)
	@make clean -C ./libft
	@make clean -C ./minilib_static
	@make clean -C ./minilib_dynamic

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all