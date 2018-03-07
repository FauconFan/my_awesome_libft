# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 11:01:01 by fauconfan         #+#    #+#              #
#    Updated: 2018/03/06 23:16:51 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ctestcom

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
CTESTCOM_LIBRARY_FOLDER = libtestcom/

NAME_LIB_CTESTCOM = ctestcom

SRC = main.c \
		malloc_utils.c \
		get_file_content.c \
		parser_origin.c \
		str_utils.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC))

OBJ = $(SRC_FP:%.c=%.o)

GWW = gcc -g -Wall -Wextra -Werror -I $(INCLUDES_FOLDER)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(CTESTCOM_LIBRARY_FOLDER)
	$(GWW) $(OBJ) -o $@ -L $(CTESTCOM_LIBRARY_FOLDER) -l $(NAME_LIB_CTESTCOM)

%.o : %.c
	$(GWW) -c $? -o $@ -L $(CTESTCOM_LIBRARY_FOLDER) -l $(NAME_LIB_CTESTCOM)

clean :
	rm -f $(OBJ)
	make -C $(CTESTCOM_LIBRARY_FOLDER) clean

fclean :
	rm -f $(OBJ)
	rm -f $(NAME)
	make -C $(CTESTCOM_LIBRARY_FOLDER) fclean

re : fclean all
