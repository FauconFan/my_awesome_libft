# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2018/08/04 15:02:59 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
NAME_A = $(NAME).a
NAME_SO = $(NAME).so

VERSION_GCC_DOCKER = latest
TEST_CMD = make

SRC_FOLDER = src/
INCLUDES_MK_FOLDER = includes_mk/
INCLUDES_FOLDER = includes/

CC = gcc
COMPILATION_FLAGS = -Wall -Wextra -Werror
INCLUDES_FLAGS = -I ./
ADDITIONAL_FLAGS =
FLAGS = $(COMPILATION_FLAGS) $(INCLUDES_FLAGS) $(ADDITIONAL_FLAGS)

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

all : compile_static_library

so : compile_dynamic_library

compile_static_library :
	@! test -f $(NAME_SO) || make fclean
	@make -C . $(NAME_A)

compile_dynamic_library :
	@! test -f $(NAME_A) || make fclean
	@make -C . $(NAME_SO) ADDITIONAL_FLAGS="-fPIC"

$(NAME_A): $(OBJ)
	@ar -rc $@ $(OBJ)
	@ranlib $@
	@echo "libft.a built successfully"

$(NAME_SO): $(OBJ)
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
	@rm -rf $(NAME_A)
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

test : $(NAME_A)
	@gcc $(SRC_FOLDER)main.c -L ./ -l ft -o test_libft $(INCLUDES_FLAGS)
	@./test_libft
	@rm -f test_libft
