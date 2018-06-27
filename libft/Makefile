# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2018/06/27 11:27:14 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

VERSION_GCC_DOCKER = latest

SRC_FOLDER = src/
INCLUDES_MK_FOLDER = includes_mk/
INCLUDES_FOLDER = includes/

CC ?= gcc
COMPILATION_FLAGS = -Wall -Wextra -Werror
INCLUDES_FLAGS = -I ./
FLAGS = $(COMPILATION_FLAGS) $(INCLUDES_FLAGS)

SRC =

include $(INCLUDES_MK_FOLDER)libft_char.mk
include $(INCLUDES_MK_FOLDER)libft_str.mk
include $(INCLUDES_MK_FOLDER)libft_put.mk
include $(INCLUDES_MK_FOLDER)libft_memmory.mk
include $(INCLUDES_MK_FOLDER)libft_math.mk
include $(INCLUDES_MK_FOLDER)libft_linked_list.mk
include $(INCLUDES_MK_FOLDER)get_next_line.mk
include $(INCLUDES_MK_FOLDER)ft_printf.mk

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

testdockercompile: fclean
	docker run -d \
			--name build_libft \
			--volume `pwd`:/libft_repo \
			-w /libft_repo \
			gcc:$(VERSION_GCC_DOCKER) \
			tail -f /dev/null
	docker exec build_libft gcc --version
	docker exec build_libft make
	docker exec build_libft make fclean
	docker rm --force build_libft

test : $(NAME)
	@gcc $(SRC_FOLDER)main.c -L ./ -l ft -o test_libft $(INCLUDES_FLAGS)
	@./test_libft
	@rm -f test_libft
