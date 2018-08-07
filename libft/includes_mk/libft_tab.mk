# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/03 16:16:36 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_TAB_FOLDER = $(SRC_FOLDER)libft_tab/

SRC_LIBFT_TAB = \
					void/ft_vtab_new.c \
					void/ft_vtab_len.c \
					void/ft_vtab_free.c \
					void/ft_vtab_insert.c \
					void/ft_vtab_push.c \
					void/ft_vtab_append.c \
					void/ft_vtab_delete.c \
					void/ft_vtab_pop.c \
					void/ft_vtab_iter.c \
					void/ft_vtab_sort.c \
					str/ft_stab_new.c \
					str/ft_stab_len.c \
					str/ft_stab_free.c \
					str/ft_stab_insert.c \
					str/ft_stab_push.c \
					str/ft_stab_append.c \
					str/ft_stab_iter.c \
					str/ft_stab_delete.c \
					str/ft_stab_pop.c \
					str/ft_stab_sort.c \

SRC += $(addprefix $(LIBFT_TAB_FOLDER), $(SRC_LIBFT_TAB))
