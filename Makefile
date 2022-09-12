# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 12:36:38 by xalbizu-          #+#    #+#              #
#    Updated: 2022/09/12 11:25:06 by xalbizu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_MLX = ./minilibx/
PATH_LIBFT = ./libft/
PATH_GNL = ./gnl/
LIBFT = $(PATH_LIBFT)libft.a
MLX = $(PATH_MLX)libmlx.a

FILES = fdf.c read_file.c draw.c isometric.c set_colours.c \
		$(PATH_GNL)get_next_line.c  $(PATH_GNL)get_next_line_utils.c

SRC = $(FILES:.c=.o)

NAME = fdf
CC = clang
CFLAGS = -Wall -Werror -Wextra
MFLAGS = -I $(PATH_MLX) -L $(PATH_MLX) -L . -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC)
	make -C $(PATH_LIBFT)
	make -C $(PATH_MLX)
	$(CC) $(CFLAGS) $(MFLAGS) $(FILES) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(PATH_LIBFT)
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)
	make clean -C $(PATH_MLX)
	make fclean -C $(PATH_LIBFT)

re: fclean all