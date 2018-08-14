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

LIBFT_ENCRYPT_FOLDER = $(SRC_FOLDER)f_encrypt/

SRC_LIBFT_ENCRYPT = \
					utils/mdx/ft_mdx_process.c \
					utils/mdx/ft_mdx_utils.c \
					utils/mdx/md5/ft_md5_func_utils.c \
					utils/mdx/md5/ft_md5_init.c \
					utils/mdx/md4/ft_md4_func_utils.c \
					utils/mdx/md4/ft_md4_init.c \
					utils/sha/funcs/ft_sha_ch_32.c \
					utils/sha/funcs/ft_sha_maj_32.c \
					utils/sha/funcs/ft_sha_parity_32.c \
					utils/sha/sha1/ft_sha1_init.c \
					utils/sha/ft_sha_utils.c \
					ft_md5.c \
					ft_md4.c \
					ft_sha1.c \
					ft_merkle_damgard_512_32.c \
					ft_merkle_damgard_512_64.c \
					ft_rotleft_uint32.c \
					ft_rotright_uint32.c \
					ft_rotleft_uint64.c \
					ft_rotright_uint64.c \

SRC += $(addprefix $(LIBFT_ENCRYPT_FOLDER), $(SRC_LIBFT_ENCRYPT))
