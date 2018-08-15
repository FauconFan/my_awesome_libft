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
					utils/base64/ft_base64_process.c \
					utils/base64/ft_unbase64_process.c \
					utils/mdx/ft_mdx_process.c \
					utils/mdx/ft_mdx_utils.c \
					utils/mdx/md5/ft_md5_func_utils.c \
					utils/mdx/md5/ft_md5_init.c \
					utils/mdx/md4/ft_md4_func_utils.c \
					utils/mdx/md4/ft_md4_init.c \
					utils/sha/funcs/ft_sha_ch_32.c \
					utils/sha/funcs/ft_sha_maj_32.c \
					utils/sha/funcs/ft_sha_parity_32.c \
					utils/sha/funcs/ft_sha_ch_64.c \
					utils/sha/funcs/ft_sha_maj_64.c \
					utils/sha/funcs/ft_sha_sig_maj_256_0.c \
					utils/sha/funcs/ft_sha_sig_maj_256_1.c \
					utils/sha/funcs/ft_sha_sig_min_256_0.c \
					utils/sha/funcs/ft_sha_sig_min_256_1.c \
					utils/sha/funcs/ft_sha_sig_maj_512_0.c \
					utils/sha/funcs/ft_sha_sig_maj_512_1.c \
					utils/sha/funcs/ft_sha_sig_min_512_0.c \
					utils/sha/funcs/ft_sha_sig_min_512_1.c \
					utils/sha/sha1/ft_sha1_init.c \
					utils/sha/sha1/ft_sha1_process.c \
					utils/sha/sha256_224/ft_sha256_init.c \
					utils/sha/sha256_224/ft_sha224_init.c \
					utils/sha/sha256_224/ft_sha256_process.c \
					utils/sha/sha256_224/sha_256_224_common.c \
					utils/sha/sha512_384/ft_sha512_init.c \
					utils/sha/sha512_384/ft_sha512_256_init.c \
					utils/sha/sha512_384/ft_sha512_224_init.c \
					utils/sha/sha512_384/ft_sha384_init.c \
					utils/sha/sha512_384/ft_sha512_process.c \
					utils/sha/sha512_384/sha_512_384_common.c \
					ft_md5.c \
					ft_md4.c \
					ft_sha1.c \
					ft_sha224.c \
					ft_sha256.c \
					ft_sha384.c \
					ft_sha512_256.c \
					ft_sha512_224.c \
					ft_sha512.c \
					ft_base64.c \
					ft_base64_url.c \
					ft_unbase64.c \
					ft_unbase64_url.c \
					ft_merkle_damgard_512_32.c \
					ft_merkle_damgard_512_64.c \
					ft_merkle_damgard_1024_64.c \
					ft_rotleft_uint32.c \
					ft_rotright_uint32.c \
					ft_rotleft_uint64.c \
					ft_rotright_uint64.c \

SRC += $(addprefix $(LIBFT_ENCRYPT_FOLDER), $(SRC_LIBFT_ENCRYPT))
