# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfa          #+#    #+#              #
#    Updated: 2019/08/11 09:51:43 by pepe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MAKEFLAGS += --no-print-directory

ALL_MODS = \
	libft_ctype \
	libft_math \
	libft_memory \
	libft_put

MODS_SELECTED = $(ALL_MODS)

.PHONY: all
all: setup_symlinks_inc_folder $(MODS_SELECTED)

libft_%: FORCE
	@ make -C $@

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
