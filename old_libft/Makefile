# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2019/01/19 09:09:06 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

SRC_FOLDER = src/
INCLUDES_MK_FOLDER = inc_mk/
INCLUDES_FOLDER = includes/

CC = gcc
COMPILATION_FLAGS = -Wall -Wextra -Werror
INCLUDES_FLAGS = -I ./
ADDITIONAL_FLAGS =
FLAGS = $(COMPILATION_FLAGS) $(INCLUDES_FLAGS) $(ADDITIONAL_FLAGS)

TOT_C = $(shell find src -mindepth 2 -name "*.c" | wc -l)

SRC =

include $(INCLUDES_MK_FOLDER)f_char.mk
include $(INCLUDES_MK_FOLDER)f_encrypt.mk
include $(INCLUDES_MK_FOLDER)f_filesystem.mk
include $(INCLUDES_MK_FOLDER)f_math.mk
include $(INCLUDES_MK_FOLDER)f_memmory.mk
include $(INCLUDES_MK_FOLDER)f_put.mk
include $(INCLUDES_MK_FOLDER)f_str.mk
include $(INCLUDES_MK_FOLDER)f_tab.mk
include $(INCLUDES_MK_FOLDER)f_utils.mk
include $(INCLUDES_MK_FOLDER)f_wchar.mk
include $(INCLUDES_MK_FOLDER)m_ft_printf.mk
include $(INCLUDES_MK_FOLDER)m_getopt.mk
include $(INCLUDES_MK_FOLDER)m_regex.mk
include $(INCLUDES_MK_FOLDER)t_rbtree.mk
include $(INCLUDES_MK_FOLDER)t_sb.mk
include $(INCLUDES_MK_FOLDER)t_slist.mk
include $(INCLUDES_MK_FOLDER)t_vb.mk

OBJ = $(SRC:%.c=%.o)

### Compilation ###

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	@ printf " %s[100%%]%s %sCompiled%s    %-70s\\n" \
		"$(_CYAN)" \
		"$(_END)" \
		"$(_GREEN)" \
		"$(_END)" \
		""
	@ ar -rc $@ $(OBJ)
	@ ranlib $@

%.o: %.c
	@ $(CC) $(FLAGS) -c $? -o $@
	@ printf " %s[%3d%%]%s %sCompiled%s    %-55s\\n" \
		"$(_CYAN)" \
		"$(shell echo $$(( 100 * $$(find src -mindepth 2 -name "*.o" | wc -l) / $(TOT_C) )))" \
		"$(_END)" \
		"$(_GREEN)" \
		"$(_END)" \
		"$?"

.PHONY: clean
clean:
	@ rm -rf $(OBJ)
	@ printf " %s[INFO]%s libft cleaned\\n" "$(_CYAN)" "$(_END)"

.PHONY: fclean
fclean:
	@ rm -rf $(OBJ)
	@ rm -rf $(NAME)
	@ printf " %s[INFO]%s libft full cleaned\\n" "$(_CYAN)" "$(_END)"

.PHONY: re
re: fclean all
