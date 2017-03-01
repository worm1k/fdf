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

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

NAME = a

SRC_PATH = .
INC_PATH = .
OBJ_PATH = .
LIB_PATH = libft

SRC_NAME =	fdf.c

INC_NAME = fdf.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft.a

all: $(NAME)
	
$(NAME): libft.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(MLX) libft/libft.a

$(LIB):
	make -C libft/

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	rm -rf $(LIB_PATH)/$(LIB)
	rm -rf $(NAME)

re: fclean all
	
norme:
	@norminette $(SRC) $(INC)
