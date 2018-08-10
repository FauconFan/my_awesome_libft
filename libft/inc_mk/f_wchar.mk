# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/03 16:02:20 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_WCHAR_FOLDER = $(SRC_FOLDER)f_wchar/

SRC_LIBFT_WCHAR = ft_wcharlen.c \
					ft_fill_wstring.c \

SRC += $(addprefix $(LIBFT_WCHAR_FOLDER), $(SRC_LIBFT_WCHAR))
