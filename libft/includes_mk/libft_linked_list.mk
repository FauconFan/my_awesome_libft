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
							ft_llist_new.c \
							ft_llist_elem_new.c \
							ft_llist_free.c \
							ft_llist_addfront.c \
							ft_llist_addback.c \
							ft_llist_size.c \
							ft_llist_iter.c \
							ft_llist_iterparam.c \
							ft_llist_iterparam2.c \
							ft_llist_map.c \
							ft_llist_merge.c \

SRC += $(addprefix $(LIBFT_LINKED_LIST_FOLDER), $(SRC_LIBFT_LINKED_LIST))
