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
					str/ft_stab_new.c \
					str/ft_stab_len.c \
					str/ft_stab_free.c \
					str/ft_stab_insert.c \
					str/ft_stab_push.c \
					str/ft_stab_append.c \
					str/ft_stab_iter.c \
					str/ft_stab_delete.c \
					str/ft_stab_pop.c \

SRC += $(addprefix $(LIBFT_TAB_FOLDER), $(SRC_LIBFT_TAB))
