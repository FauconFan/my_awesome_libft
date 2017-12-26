# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/15 18:16:07 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FOLDER = src/
INCLUDES_MK_FOLDER = includes_mk/
INCLUDES_FOLDER = includes/
CONVERTERS_FT_PRINTF_FOLDER = converters/

LIBFT_CHAR_FOLDER = libft_char/
LIBFT_STR_FOLDER = libft_str/
LIBFT_PUT_FOLDER = libft_put/
LIBFT_MEMMORY_FOLDER = libft_memmory/
LIBFT_MATH_FOLDER = libft_math/
LIBFT_LINKED_LIST_FOLDER = libft_linked_list/
GET_NEXT_LINE_FOLDER = get_next_line/
FT_PRINTF_FOLDER = ft_printf/

CC ?= gcc
COMPILATION_FLAGS = -Wall -Wextra -Werror
INCLUDES_FLAGS = -I $(INCLUDES_FOLDER) -I ./
FLAGS = $(COMPILATION_FLAGS) $(INCLUDES_FLAGS)

include $(INCLUDES_MK_FOLDER)libft_char.mk
include $(INCLUDES_MK_FOLDER)libft_str.mk
include $(INCLUDES_MK_FOLDER)libft_put.mk
include $(INCLUDES_MK_FOLDER)libft_memmory.mk
include $(INCLUDES_MK_FOLDER)libft_math.mk
include $(INCLUDES_MK_FOLDER)libft_linked_list.mk
include $(INCLUDES_MK_FOLDER)get_next_line.mk
include $(INCLUDES_MK_FOLDER)ft_printf.mk

SRC = $(SRC_LIBFT_CHAR_FP) \
		$(SRC_LIBFT_STR_FP) \
		$(SRC_LIBFT_PUT_FP) \
		$(SRC_LIBFT_MEMMORY_FP) \
		$(SRC_LIBFT_MATH_FP) \
		$(SRC_LIBFT_LINKED_LIST_FP) \
		$(SRC_GET_NEXT_LINE_FP) \
		$(SRC_FT_PRINTF_FP) \

OBJ = $(SRC:%.c=%.o)

all : $(NAME)
	@echo builted with $(CC)

$(NAME) : $(OBJ)
	@ar -rc $@ $(OBJ)
	@ranlib $@
	@printf "                                                                \r"
	@echo "libft built successfully"

%.o : %.c
	@printf "                                                                \r"
	@printf "  🍏  <= $?\r"
	@$(CC) $(FLAGS) -c $? -o $@

clean :
	@rm -rf $(OBJ)
	@echo "libft cleaned"

fclean :
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@echo "libft fcleaned"

re : fclean all

test : $(NAME)
	@gcc $(SRC_FOLDER)main.c -L ./ -l ft -o test_libft $(INCLUDES_FLAGS)
	@./test_libft
	@rm -f test_libft
