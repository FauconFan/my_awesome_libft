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

LIBFT_STRING_BUFFER_FOLDER = $(SRC_FOLDER)t_sb/

SRC_LIBFT_STRING_BUFFER = \
							ft_sb_new.c \
							ft_sb_free.c \
							ft_sb_append.c \
							ft_sb_tostring.c \

SRC += $(addprefix $(LIBFT_STRING_BUFFER_FOLDER), $(SRC_LIBFT_STRING_BUFFER))
