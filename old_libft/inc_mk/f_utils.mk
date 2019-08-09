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

LIBFT_UTILS_FOLDER = $(SRC_FOLDER)f_utils/

SRC_LIBFT_UTILS = \
					ft_for.c \
					ft_fori.c \
					ft_forparam.c \
					ft_foriparam.c \

SRC += $(addprefix $(LIBFT_UTILS_FOLDER), $(SRC_LIBFT_UTILS))
