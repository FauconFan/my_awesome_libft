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

LIBFT_SIMPLE_LIST_FOLDER = $(SRC_FOLDER)t_slist/

SRC_LIBFT_SIMPLE_LIST = \
							core/ft_slist_new.c \
							core/ft_slist_cpy.c \
							core/ft_slist_free.c \
							core/ft_slist_elem_new.c \
							core/ft_slist_add_cmp.c \
							core/ft_slist_add_cpy.c \
							modify/ft_slist_addfront.c \
							modify/ft_slist_addback.c \
							modify/ft_slist_push.c \
							modify/ft_slist_push_cp.c \
							modify/ft_slist_append.c \
							modify/ft_slist_append_cp.c \
							modify/ft_slist_pop.c \
							modify/ft_slist_remove.c \
							modify/ft_slist_merge.c \
							modify/ft_slist_mergeone.c \
							modify/ft_slist_rev.c \
							modify/ft_slist_sort.c \
							static/ft_slist_size.c \
							static/ft_slist_isempty.c \
							static/ft_slist_get.c \
							static/ft_slist_head.c \
							static/ft_slist_last.c \
							treat/ft_slist_iter.c \
							treat/ft_slist_iteri.c \
							treat/ft_slist_iterparam.c \
							treat/ft_slist_iteriparam.c \
							treat/ft_slist_iterparam2.c \
							treat/ft_slist_iteriparam2.c \
							treat/ft_slist_find.c \
							treat/ft_slist_findparam.c \
							treat/ft_slist_map.c \

SRC += $(addprefix $(LIBFT_SIMPLE_LIST_FOLDER), $(SRC_LIBFT_SIMPLE_LIST))
