# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 19:01:46 by fauconfa          #+#    #+#              #
#    Updated: 2018/06/27 16:24:41 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = build_custom

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/

FLAGS = -Wall -Wextra -Werror

PARAM = ""

SRC = \
		main.c \
		bc_file_depedencies.c \
		bc_str_utils.c \
		bc_read_utils.c \
		bc_file_utils.c \
		bc_simple_list_utils.c \
		bc_project_depedencies.c \
		bc_make_rendu.c \

OBJ_TMP = $(SRC:%.c=%.o)

OBJ = $(addprefix $(SRC_FOLDER), $(OBJ_TMP))

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME) -I $(INCLUDES_FOLDER)

%.o: %.c
	gcc $(FLAGS) -c $? -o $@ -I $(INCLUDES_FOLDER)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run: all
	./$(NAME) $(PARAM)
	make fclean
