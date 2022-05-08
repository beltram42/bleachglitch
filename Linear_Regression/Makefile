# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alambert <alambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 11:54:36 by alambert          #+#    #+#              #
#    Updated: 2022/05/08 17:08:55 by alambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = display
MLX = ./mlx/libmlx.a
CC = clang
SRC = display.c

SEC = 20
OBJ = $(SRC:.c=.o)
CFLAGS = -D SECONDS=$(SEC)
FL_MLX = -ldl -lmlx -Lmlx -lm -lXext -lX11 -L/usr/lib/aarch64 -Imlx mlx/libmlx.a

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	make re -C ./mlx
	$(CC) $(CFLAGS) $(FL_MLX) $(OBJ) -o $(NAME) $(MLX)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(MAKE) clean -C ./mlx
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./mlx
	$(RM) $(NAME)

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long map_set/xl_map.ber

re: fclean all

.PHONY: all clean fclean re
