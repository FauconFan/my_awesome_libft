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

LIBFT_STR_FOLDER = $(SRC_FOLDER)f_str/
SIMPLE_LIBFT_STR_FOLDER = $(LIBFT_STR_FOLDER)simple/
INTEGER_LIBFT_STR_FOLDER = $(LIBFT_STR_FOLDER)integer/
ALLOC_LIBFT_STR_FOLDER = $(LIBFT_STR_FOLDER)alloc/
TREAT_LIBFT_STR_FOLDER = $(LIBFT_STR_FOLDER)treat/

SRC_LIBFT_TREAT_STR = \
					ft_strcat.c \
					ft_strchr.c \
					ft_strclr.c \
					ft_strcmp.c \
					ft_strcpos.c \
					ft_strcpy.c \
					ft_strcrpos.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strncat.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strnstr.c \
					ft_strparse.c \
					ft_strparse_n_free.c \
					ft_strpos.c \
					ft_strrchr.c \
					ft_strrpos.c \
					ft_strsplit.c \
					ft_strstr.c \
					ft_strsub.c \
					ft_strtrim.c \

SRC_LIBFT_SIMPLE_STR = \
					ft_str_all.c \
					ft_str_any.c \
					ft_str_is_alnum.c \
					ft_str_is_alpha.c \
					ft_str_is_ascii.c \
					ft_str_is_blank.c \
					ft_str_is_lowercase.c \
					ft_str_is_numeric.c \
					ft_str_is_printable.c \
					ft_str_is_uppercase.c \

SRC_LIBFT_INTEGER_STR = \
					ft_atoi_base.c \
					ft_atoi.c \
					ft_convert_base.c \
					ft_itoa_base.c \
					ft_itoa.c \
					ft_lltoa.c \

SRC_LIBFT_ALLOC_STR = \
					ft_strdel.c \
					ft_strdup.c \
					ft_strndup.c \
					ft_strnew.c \
					ft_strsetnew.c \
					ft_strjoin.c \


SRC += $(addprefix $(TREAT_LIBFT_STR_FOLDER), $(SRC_LIBFT_TREAT_STR)) \
		$(addprefix $(SIMPLE_LIBFT_STR_FOLDER), $(SRC_LIBFT_SIMPLE_STR)) \
		$(addprefix $(INTEGER_LIBFT_STR_FOLDER), $(SRC_LIBFT_INTEGER_STR)) \
		$(addprefix $(ALLOC_LIBFT_STR_FOLDER), $(SRC_LIBFT_ALLOC_STR))
