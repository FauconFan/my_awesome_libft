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

REGEX_FOLDER = $(SRC_FOLDER)m_regex/

SRC_REGEX = \
						utils/rv_match.c \
						utils/rv_match_star.c \
						utils/rv_match_plus.c \
						utils/rv_match_group.c \
						utils/rv_match_questionmark.c \
						ft_rg_match.c \

SRC += $(addprefix $(REGEX_FOLDER), $(SRC_REGEX))
