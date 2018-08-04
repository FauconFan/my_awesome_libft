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

LIBFT_LINKED_LIST_FOLDER = $(SRC_FOLDER)libft_linked_list/

SRC_LIBFT_LINKED_LIST = \
							ft_lstaddback.c \
							ft_lstaddfront.c \
							ft_lstfree.c \
							ft_lstiter.c \
							ft_lstiterparam.c \
							ft_lstmap.c \
							ft_lstmapparam.c \
							ft_lstmerge.c \
							ft_lstnew.c \
							ft_lstsize.c \

SRC += $(addprefix $(LIBFT_LINKED_LIST_FOLDER), $(SRC_LIBFT_LINKED_LIST))
