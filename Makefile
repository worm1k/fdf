# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abykov <abykov@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 15:51:41 by abykov            #+#    #+#              #
#    Updated: 2017/02/12 17:54:42 by abykov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

NAME = fdf

SRC_PATH = .
INC_PATH = .
OBJ_PATH = .
LIB_PATH = libft

SRC_NAME =	fdf.c \
			read_data.c \
			print.c \
			isvalid.c \
			fd_atoi.c \
			draw.c \
			transform.c \
			rotate.c \
			ft_minmax.c \
			draw_norme.c \
			read_norm.c \
			color.c

INC_NAME = fdf.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft.a

all: $(LIB) $(NAME)
	
$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(MLX) $(LIB_PATH)/$(LIB)

$(LIB):
	make -C $(LIB_PATH)/

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c  $(INC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make -C $(LIB_PATH)/ clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB_PATH)/$(LIB)

re: fclean all
	
