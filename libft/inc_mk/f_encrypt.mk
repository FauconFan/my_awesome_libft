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
LIBFT_MDX_FOLDER = $(LIBFT_ENCRYPT_FOLDER)mdx/
LIBFT_SHA_FOLDER = $(LIBFT_ENCRYPT_FOLDER)sha/
LIBFT_B64_FOLDER = $(LIBFT_ENCRYPT_FOLDER)base64/
LIBFT_DES_FOLDER = $(LIBFT_ENCRYPT_FOLDER)des/

SRC_LIBFT_MDX = \
					ft_mdx_process.c \
					ft_mdx_utils.c \
					md5/ft_md5_func_utils.c \
					md5/ft_md5_init.c \
					md4/ft_md4_func_utils.c \
					md4/ft_md4_init.c \

SRC_LIBFT_SHA = \
					funcs/ft_sha_ch_32.c \
					funcs/ft_sha_maj_32.c \
					funcs/ft_sha_parity_32.c \
					funcs/ft_sha_ch_64.c \
					funcs/ft_sha_maj_64.c \
					funcs/ft_sha_sig_maj_256_0.c \
					funcs/ft_sha_sig_maj_256_1.c \
					funcs/ft_sha_sig_min_256_0.c \
					funcs/ft_sha_sig_min_256_1.c \
					funcs/ft_sha_sig_maj_512_0.c \
					funcs/ft_sha_sig_maj_512_1.c \
					funcs/ft_sha_sig_min_512_0.c \
					funcs/ft_sha_sig_min_512_1.c \
					sha1/ft_sha1_init.c \
					sha1/ft_sha1_process.c \
					sha256_224/ft_sha256_init.c \
					sha256_224/ft_sha224_init.c \
					sha256_224/ft_sha256_process.c \
					sha256_224/sha_256_224_common.c \
					sha512_384/ft_sha512_init.c \
					sha512_384/ft_sha512_256_init.c \
					sha512_384/ft_sha512_224_init.c \
					sha512_384/ft_sha384_init.c \
					sha512_384/ft_sha512_process.c \
					sha512_384/sha_512_384_common.c \

SRC_LIBFT_B64 = \
					ft_base64_process.c \
					ft_unbase64_process.c \
					ft_unbase64_process_utils.c \

SRC_LIBFT_DES = \
					modes/ft_des_ecb.c \
					modes/ft_des_cbc.c \
					modes/ft_des_pcbc.c \
					modes/ft_des_cfb.c \
					modes/ft_des_ofb.c \
					des_globals.c \
					ft_des_process_block.c \
					ft_des_padding.c \
					ft_des_funcs.c \
					ft_des_funcs2.c \
					ft_des_funcs3.c \

SRC_LIBFT_ENCRYPT = \
					ft_md5.c \
					ft_md4.c \
					ft_sha1.c \
					ft_sha224.c \
					ft_sha256.c \
					ft_sha384.c \
					ft_sha512_256.c \
					ft_sha512_224.c \
					ft_sha512.c \
					ft_hmac_init_free.c \
					ft_hmac_process.c \
					ft_base64.c \
					ft_base64_url.c \
					ft_unbase64.c \
					ft_unbase64_url.c \
					ft_merkle_damgard_512_pad32_s32.c \
					ft_merkle_damgard_512_pad64_s32.c \
					ft_merkle_damgard_512_pad64_s64.c \
					ft_merkle_damgard_1024_pad128_s64.c \
					ft_rotleft_uint32.c \
					ft_rotright_uint32.c \
					ft_rotleft_uint64.c \
					ft_rotright_uint64.c \
					ft_des_new.c \
					ft_des_process.c \
					ft_des_utils.c \

SRC += $(addprefix $(LIBFT_MDX_FOLDER), $(SRC_LIBFT_MDX))
SRC += $(addprefix $(LIBFT_SHA_FOLDER), $(SRC_LIBFT_SHA))
SRC += $(addprefix $(LIBFT_B64_FOLDER), $(SRC_LIBFT_B64))
SRC += $(addprefix $(LIBFT_DES_FOLDER), $(SRC_LIBFT_DES))
SRC += $(addprefix $(LIBFT_ENCRYPT_FOLDER), $(SRC_LIBFT_ENCRYPT))
