# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2019/08/17 11:59:12 by pepe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAKEFLAGS += --no-print-directory

ALL_MODS = \
	libft_ctype \
	libft_math \
	libft_memory \
	libft_put \
	libft_strstd \
	libft_strconv \
	libft_strlambda \
	libft_strctype \
	libft_wchar \
	libft_tabvoid \
	libft_tabstr \
	libft_structslist

MODS_SELECTED = $(ALL_MODS)

.PHONY: all
all: setup_symlinks_inc_folder $(MODS_SELECTED)

libft_%: FORCE
	@ make -C $@

libft_strstd: libft_memory
libft_strconv: libft_strstd libft_memory libft_math libft_ctype
libft_strlambda: libft_strstd libft_memory
libft_strctype: libft_strlambda libft_ctype
libft_tabvoid: libft_memory
libft_tabstr: libft_memory libft_strstd libft_tabvoid
libft_structslist: libft_memory libft_tabvoid

.PHONY: clean
clean:
	@ $(foreach mod, $(ALL_MODS), make -C $(mod) clean;)

.PHONY: fclean
fclean:
	@ $(foreach mod, $(ALL_MODS), make -C $(mod) fclean;)
	@ rm -rf $(NAME)

.PHONY: re
re:
	@ make -C . fclean
	@ make -C . all

.PHONY: setup_symlinks_inc_folder
setup_symlinks_inc_folder:
	@ rm -rf inc/
	@ mkdir inc/
	@ $(foreach mod, $(ALL_MODS), \
		for header in $(mod)/inc/*; do \
			(BASE=$$(basename $$header); set -x; ln -s ../$$header inc/$$BASE) ; \
		done \
	;)
	@ (set -x; ln -s ../common/common.h inc/common.h)

.PHONY: FORCE
FORCE:
