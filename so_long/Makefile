# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alambert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 16:48:37 by alambert          #+#    #+#              #
#    Updated: 2022/03/24 17:03:17 by alambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =

OBJS = $(SRCS:.c=.o)

NAMW = so_long

CC = gcc

CFAGS = -Wall -Werror -Wextra -L./mlx_macos -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	make re -C ./libft
	make re -C ./mlx_macos
	$(CC) $(CFLAGS) $(OBJ) -L./Libft -lft -0 $(NAME)

clean:
	make re -C ./libft
	make clean -C ./mlx_macos
	$(RM) $(OBJS)

fclean:
	make fclean -C ./libft
	make clean -C ./mlx_macos

re: fclean all

.PHONY: all clean fclean re
