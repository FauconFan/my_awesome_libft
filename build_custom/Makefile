# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 19:01:46 by fauconfa          #+#    #+#              #
#    Updated: 2018/06/25 17:23:40 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

all : fclean $(OBJ)
	gcc $(FLAGS) $(OBJ) -I $(INCLUDES_FOLDER)
	./a.out $(PARAM)
	make fclean

%.o : %.c
	gcc $(FLAGS) -c $? -o $@ -I $(INCLUDES_FOLDER)

clean :
	@rm -rf ./a.out
	@rm -rf $(OBJ)

fclean : clean

re : fclean all
