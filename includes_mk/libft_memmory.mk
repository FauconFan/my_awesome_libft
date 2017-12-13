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

SRC_LIBFT_MEMMORY = ft_bzero.c \
						ft_memalloc.c \
						ft_memcheck.c \
						ft_memccpy.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memcpy.c \
						ft_memdel.c \
						ft_memmove.c \
						ft_memset.c \
						ft_die.c \

SRC_LIBFT_MEMMORY_FP = $(addprefix $(SRC_FOLDER)$(LIBFT_MEMMORY_FOLDER), $(SRC_LIBFT_MEMMORY))
