# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2019/08/11 10:00:36 by pepe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Expect SRC to be filled
## Expect MOD_NAME to be filled

NAME = ../libft.a

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

MAKEFLAGS += --no-print-directory

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_DEP = -MT $@ -MD -MP -MF $(@:.o=.d)
IFLAGS = -I inc/ -I ../common/
ADD_FLAGS =

ifeq ($(CC), clang)
	CFLAGS += -Weverything
endif

FLAGS = $(CFLAGS) $(CFLAGS_DEP) $(IFLAGS) $(ADD_FLAGS)


TOT_C = $(shell find src -mindepth 1 -name "*.c" | wc -l)

OBJ = $(SRC:%.c=%.o)
DEP = $(SRC:%.c=%.d)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) FORCE
	@ printf " %s[ 100 %%]%s libft - %s %sCompiled%s    %-70s\\n" \
		"$(_CYAN)" \
		"$(_END)" \
		"$(MOD_NAME)" \
		"$(_GREEN)" \
		"$(_END)" \
		""
	@ ar -rc $@ $(OBJ)
	@ ranlib $@

%.o: %.c
	@ $(CC) $(FLAGS) -c $< -o $@
	@ printf " %s[ %3d %%]%s %sCompiled%s    %-55s\\n" \
		"$(_CYAN)" \
		"$(shell echo $$(( 100 * $$(find src -mindepth 1 -name "*.o" | wc -l) / $(TOT_C) )))" \
		"$(_END)" \
		"$(_GREEN)" \
		"$(_END)" \
		"$<"

-include $(DEP)

.PHONY: clean
clean:
	@ rm -rf $(OBJ)
	@ rm -rf $(DEP)
	@ printf " %s[ INFO ]%s libft - %s cleaned\\n" "$(_CYAN)" "$(_END)" "$(MOD_NAME)"

.PHONY: fclean
fclean: clean

.PHONY: re
re: fclean all

.PHONY: FORCE
FORCE: