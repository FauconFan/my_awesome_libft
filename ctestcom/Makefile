# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/14 11:01:01 by fauconfa          #+#    #+#              #
#    Updated: 2018/06/25 16:03:38 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ctestcom

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
CTESTCOM_LIBRARY_FOLDER = libtestcom/

NAME_LIB_CTESTCOM = ctestcom

PATH_LIB_CTESTCOM = $(CTESTCOM_LIBRARY_FOLDER)lib$(NAME_LIB_CTESTCOM).a

SRC = main.c \
		malloc_utils.c \
		get_file_content.c \
		parser_origin.c \
		str_utils.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC))

OBJ = $(SRC_FP:%.c=%.o)

GWW = gcc -Wall -Wextra -Werror -I $(INCLUDES_FOLDER)

all : $(NAME)

$(NAME) : $(OBJ) $(PATH_LIB_CTESTCOM)
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

$(PATH_LIB_CTESTCOM):
	make -C $(CTESTCOM_LIBRARY_FOLDER)

testctestcom : all $(PATH_LIB_CTESTCOM)
	make -C $(CTESTCOM_LIBRARY_FOLDER)
	@./$(NAME) src/main.c testmain.c
	@gcc testmain.c -L $(CTESTCOM_LIBRARY_FOLDER) -l ctestcom -I $(CTESTCOM_LIBRARY_FOLDER)$(INCLUDES_FOLDER) -o testmain
	@./testmain
	@rm -f ./testmain testmain.c

re : fclean all
