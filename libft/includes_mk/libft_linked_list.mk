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
							core/ft_llist_free.c \
							core/ft_llist_elem_new.c \
							core/ft_llist_add_cmp.c \
							core/ft_llist_cpy.c \
							core/ft_llist_add_cpy.c \
							core/ft_llist_new.c \
							modify/ft_llist_pop.c \
							modify/ft_llist_remove.c \
							modify/ft_llist_addfront.c \
							modify/ft_llist_merge.c \
							modify/ft_llist_rev.c \
							modify/ft_llist_mergeone.c \
							modify/ft_llist_sort.c \
							modify/ft_llist_addback.c \
							static/ft_llist_last.c \
							static/ft_llist_head.c \
							static/ft_llist_isempty.c \
							static/ft_llist_get.c \
							static/ft_llist_size.c \
							treat/ft_llist_iter.c \
							treat/ft_llist_iteri.c \
							treat/ft_llist_iterparam.c \
							treat/ft_llist_iteriparam.c \
							treat/ft_llist_iterparam2.c \
							treat/ft_llist_iteriparam2.c \
							treat/ft_llist_find.c \
							treat/ft_llist_findparam.c \
							treat/ft_llist_map.c \

SRC += $(addprefix $(LIBFT_LINKED_LIST_FOLDER), $(SRC_LIBFT_LINKED_LIST))
