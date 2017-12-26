# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 19:01:46 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/26 18:16:49 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/

FLAGS = -g -Wall -Wextra -Werror

SRC = main.c \
		bc_file_depedencies.c \
		bc_str_utils.c \
		bc_read_utils.c \
		bc_file_utils.c \
		bc_simple_list_utils.c \
		bc_project_depedencies.c \

OBJ_TMP = $(SRC:%.c=%.o)

OBJ = $(addprefix $(SRC_FOLDER), $(OBJ_TMP))

all : clean $(OBJ)
	gcc $(FLAGS) $(OBJ) -I $(INCLUDES_FOLDER)
	@./a.out

%.o : %.c
	gcc $(FLAGS) -c $? -o $@ -I $(INCLUDES_FOLDER)

clean :
	@rm -rf ./a.out
	@rm -rf $(OBJ)
