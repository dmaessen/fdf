# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 18:52:54 by dmaessen          #+#    #+#              #
#    Updated: 2023/05/31 10:53:43 by dmaessen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

LIBFT = libft/libft.a

HEADER = -I MLX42/include -I fdf.h

LIB = MLX42/build/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit $(LIBFT)

SRC =  main.c read.c draw.c draw2.c free_error.c utils.c init.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

libmlx42:
	@cmake MLX42 -B MLX42/build && make -C MLX42/build -j4

libft_build:
	$(MAKE) -C libft/

$(NAME): libmlx42 libft_build $(OBJ) 
	$(CC) $(OBJ) $(LIB) $(HEADER) -o $(NAME)

clean:
	make clean -C libft/
	make clean -C MLX42/build/
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIBFT)
	rm -f MLX42/build/libmlx42.a
	rm -f $(NAME)

re: fclean all

.PHONY:	all, clean, fclean, re, libmlx42, libft_build