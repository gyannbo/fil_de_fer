# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbonis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 13:36:59 by gbonis            #+#    #+#              #
#    Updated: 2024/05/20 15:35:09 by gbonis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	alg_utils.c\
	controls.c\
	draw.c\
	draw_line.c\
	fdf.c\
	parse_map.c\
	project.c\
	utils.c\
	check_valid.c\
	compound_free.c\
	free.c\
	free2.c\
	syscalls_protec.c\

HEADER = fdf.h

LIBFT = ./libft/libft.a

GET_NEXT_LINE = ./get_next_line.o

MLX = ./minilibx-linux/libmlx.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

NAME = fdf 

all : $(NAME)

$(NAME):  $(OBJ) $(HEADER) $(LIBFT) $(GET_NEXT_LINE) $(MLX)  Makefile
	 $(CC) $(CFLAGS) -Iminilibx-linux $(OBJ) $(GET_NEXT_LINE) $(MLX) $(LIBFT) -lX11 -lXext -lm -o fdf 

$(LIBFT) :
	make -C ./libft

$(GET_NEXT_LINE) : get_next_line/get_next_line.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c ./get_next_line/get_next_line.c 

$(MLX) :
	make -C ./minilibx-linux

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c  $< 

clean : 
	make -C ./libft clean
	make -C ./minilibx-linux clean
	rm -f $(OBJ) get_next_line.o

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re : fclean all 

.PHONY: all clean fclean re
