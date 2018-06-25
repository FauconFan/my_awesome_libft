# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2018/06/25 13:49:20 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FOLDER = src/
INCLUDES_MK_FOLDER = includes_mk/
INCLUDES_FOLDER = includes/

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
INCLUDES_FLAGS = -I ./
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
	@echo "libft built successfully"

%.o : %.c
	@printf "Compiling $?... "
	@$(CC) $(FLAGS) -c $? -o $@
	@printf "compiled\\n"

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
