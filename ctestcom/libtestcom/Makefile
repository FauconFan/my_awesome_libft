# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 11:01:35 by fauconfan         #+#    #+#              #
#    Updated: 2018/03/20 11:22:18 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libctestcom.a
NAME_MAIN_TEST = test_libtestcom

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/

SRC = env_utils.c \
		malloc_utils.c \
		assert_standards.c \
		assert_primitives.c \

MAIN_TEST = $(SRC_FOLDER)main_test.c

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC))

OBJ = $(SRC_FP:%.c=%.o)

GWW = gcc -Wall -Wextra -Werror -I $(INCLUDES_FOLDER)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $@ $(OBJ)
	@ranlib $@

%.o : %.c
	$(GWW) -c $? -o $@

clean :
	@rm -f $(OBJ)

fclean :
	@rm -f $(OBJ)
	@rm -f $(NAME)

re : fclean all
