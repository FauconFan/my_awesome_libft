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

LIBFT_MATH_FOLDER = $(SRC_FOLDER)libft_math/

SRC_LIBFT_MATH = ft_abs.c \
					ft_log10.c \
					ft_logb.c \
					ft_max.c \
					ft_min.c \
					ft_pow.c \
					ft_sqrt.c \
					ft_curt.c \
					ft_nrt.c

SRC += $(addprefix $(LIBFT_MATH_FOLDER), $(SRC_LIBFT_MATH))
