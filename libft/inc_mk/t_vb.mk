# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/03 16:35:59 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_VOID_BUFFER_FOLDER = $(SRC_FOLDER)t_vb/

SRC_LIBFT_VOID_BUFFER = \
						ft_vb_elem_new.c \
						ft_vb_elem_free.c \
						ft_vb_new.c \
						ft_vb_free.c \
						ft_vb_append.c \
						ft_vb_tobuffer.c \

SRC += $(addprefix $(LIBFT_VOID_BUFFER_FOLDER), $(SRC_LIBFT_VOID_BUFFER))
