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

LIBFT_RB_TREE_FOLDER = $(SRC_FOLDER)t_rbtree/

SRC_LIBFT_RB_TREE = \
					ft_rbt_delete.c \
					ft_rbt_delete_utils.c \
					ft_rbt_free.c \
					ft_rbt_init.c \
					ft_rbt_insert.c \
					ft_rbt_insert_utils.c \
					ft_rbt_lookup.c \
					ft_rbt_node_init.c \
					ft_rbt_node_lookup.c \
					ft_rbt_node_replace.c \
					ft_rbt_rotate.c \
					ft_rbt_utils.c \

SRC += $(addprefix $(LIBFT_RB_TREE_FOLDER), $(SRC_LIBFT_RB_TREE))
