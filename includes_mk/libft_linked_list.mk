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

SRC_LIBFT_LINKED_LIST = ft_lstadd.c \
							ft_lstfree.c \
							ft_lstiter.c \
							ft_lstmap.c \
							ft_lstnew.c \
							ft_lstsize.c \
							ft_lstmerge.c \

SRC_LIBFT_LINKED_LIST_FP = $(addprefix $(SRC_FOLDER)$(LIBFT_LINKED_LIST_FOLDER), $(SRC_LIBFT_LINKED_LIST))
