# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2018/08/06 13:53:07 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
NAME_A = $(NAME).a
NAME_SO = $(NAME).so

VERSION_GCC_DOCKER = latest
TEST_CMD = make

_RED=$(shell tput setaf 1)
_GREEN=$(shell tput setaf 2)
_YELLOW=$(shell tput setaf 3)
_BLUE=$(shell tput setaf 4)
_PURPLE=$(shell tput setaf 5)
_CYAN=$(shell tput setaf 6)
_WHITE=$(shell tput setaf 7)
_END=$(shell tput sgr0)

SRC_FOLDER = src/
INCLUDES_MK_FOLDER = includes_mk/
INCLUDES_FOLDER = includes/

CC = gcc
COMPILATION_FLAGS = -g -Wall -Wextra -Werror
INCLUDES_FLAGS = -I ./
ADDITIONAL_FLAGS =
FLAGS = $(COMPILATION_FLAGS) $(INCLUDES_FLAGS) $(ADDITIONAL_FLAGS)

TOT_C = $(shell find src -mindepth 2 -name "*.c" | wc -l)

SRC =

include $(INCLUDES_MK_FOLDER)ft_printf.mk
include $(INCLUDES_MK_FOLDER)get_next_line.mk
include $(INCLUDES_MK_FOLDER)getopt.mk
include $(INCLUDES_MK_FOLDER)libft_char.mk
include $(INCLUDES_MK_FOLDER)libft_linked_list.mk
include $(INCLUDES_MK_FOLDER)libft_math.mk
include $(INCLUDES_MK_FOLDER)libft_memmory.mk
include $(INCLUDES_MK_FOLDER)libft_put.mk
include $(INCLUDES_MK_FOLDER)libft_str.mk
include $(INCLUDES_MK_FOLDER)libft_tab.mk
include $(INCLUDES_MK_FOLDER)libft_wchar.mk

OBJ = $(SRC:%.c=%.o)

### Compilation ###

all: compile_static_library

so: compile_dynamic_library

compile_static_library:
	@! test -f $(NAME_SO) || make fclean
	@make -C . $(NAME_A)

compile_dynamic_library:
	@! test -f $(NAME_A) || make fclean
	@make -C . $(NAME_SO) ADDITIONAL_FLAGS="-fPIC"

$(NAME_A): $(OBJ)
	@ar -rc $@ $(OBJ)
	@ranlib $@
	@echo "libft.a built successfully"

$(NAME_SO): $(OBJ)
	@$(CC) -shared -Wl,-soname,$(NAME_SO) -o $(NAME_SO) $(OBJ)
	@echo "libft.so built successfully"

%.o: %.c
	@printf "%s[----] Compiling%s   %-55s" "$(_PURPLE)" "$(_END)" "$?"
	@$(CC) $(FLAGS) -c $? -o $@
	@printf "\\r"
	@printf "%s[%3d%%]%s %sCompiled%s    %-55s\\n" \
		"$(_CYAN)" \
		"$(shell echo $$(( 100 * $$(find src -name "*.o" | wc -l) / $(TOT_C) )))" \
		"$(_END)" \
		"$(_GREEN)" \
		"$(_END)" \
		"$?"

clean:
	@rm -rf $(OBJ)
	@echo "libft cleaned"

fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME_A)
	@rm -rf $(NAME_SO)
	@echo "libft fcleaned"

re: fclean all

### Test stuff ###

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

test: $(NAME_A)
	@gcc -g $(SRC_FOLDER)main.c -L ./ -l ft -o test_libft $(INCLUDES_FLAGS)
	@valgrind --leak-check=full ./test_libft
	@rm -f test_libft
