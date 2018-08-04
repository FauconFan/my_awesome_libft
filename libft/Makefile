# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2018/08/04 14:12:45 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
NAME_SO = libft.so

VERSION_GCC_DOCKER = latest
TEST_CMD = make

SRC_FOLDER = src/
INCLUDES_MK_FOLDER = includes_mk/
INCLUDES_FOLDER = includes/

CC = gcc
COMPILATION_FLAGS = -Wall -Wextra -Werror
INCLUDES_FLAGS = -I ./
ADDITIONAL_FLGAS =
FLAGS = $(COMPILATION_FLAGS) $(INCLUDES_FLAGS) $(ADDITIONAL_FLGAS)

SRC =

include $(INCLUDES_MK_FOLDER)ft_printf.mk
include $(INCLUDES_MK_FOLDER)get_next_line.mk
include $(INCLUDES_MK_FOLDER)libft_char.mk
include $(INCLUDES_MK_FOLDER)libft_linked_list.mk
include $(INCLUDES_MK_FOLDER)libft_math.mk
include $(INCLUDES_MK_FOLDER)libft_memmory.mk
include $(INCLUDES_MK_FOLDER)libft_put.mk
include $(INCLUDES_MK_FOLDER)libft_str.mk
include $(INCLUDES_MK_FOLDER)libft_wchar.mk

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

so : $(NAME_SO)

$(NAME) :
	@! test -f $(NAME_SO) || make fclean
	@make -C . $(OBJ)
	@ar -rc $@ $(OBJ)
	@ranlib $@
	@echo "libft.a built successfully"

$(NAME_SO) :
	@! test -f $(NAME) || make fclean
	@make -C . $(OBJ) ADDITIONAL_FLGAS="-fPIC"
	@$(CC) -shared -Wl,-soname,$(NAME_SO) -o $(NAME_SO) $(OBJ)
	@echo "libft.so built successfully"

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
	@rm -rf $(NAME_SO)
	@echo "libft fcleaned"

re : fclean all

test_docker_compile_gcc: fclean
	docker run -d \
			--name build_libft_gcc \
			--volume `pwd`:/libft_repo \
			-w /libft_repo \
			gcc:$(VERSION_GCC_DOCKER) \
			tail -f /dev/null
	docker exec build_libft_gcc gcc --version
	docker exec build_libft_gcc $(TEST_CMD)
	docker exec build_libft_gcc make fclean
	docker stop build_libft_gcc
	docker rm build_libft_gcc

test_docker_compile_clang: fclean
	docker run -d \
			--name build_libft_clang \
			--volume `pwd`:/libft_repo \
			-w /libft_repo \
			debian \
			tail -f /dev/null
	docker exec build_libft_clang apt-get update
	docker exec build_libft_clang apt-get install -y clang make
	docker exec build_libft_clang $(TEST_CMD) CC=clang
	docker exec build_libft_clang make fclean
	docker stop build_libft_clang
	docker rm build_libft_clang

test : $(NAME)
	@gcc $(SRC_FOLDER)main.c -L ./ -l ft -o test_libft $(INCLUDES_FLAGS)
	@./test_libft
	@rm -f test_libft
