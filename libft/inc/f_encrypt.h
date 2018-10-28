/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_encrypt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:50:41 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/28 11:17:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_ENCRYPT_H
# define F_ENCRYPT_H

# include "libft.h"
# include "inc/encrypt_utils/mdx.h"
# include "inc/encrypt_utils/sha.h"
# include "inc/encrypt_utils/base64.h"
# include "inc/encrypt_utils/des.h"
# include "inc/encrypt_utils/hmac.h"

typedef struct		s_merkle_damgard_config
{
	size_t			size_blocks;
	size_t			padding_end;
	size_t			size_size_end;
	size_t			size_swap;
	t_bool			content_to_little_endian;
}					t_merkle_damgard_config;

/*
**	Source:
**
**	MD4		http://www.faqs.org/rfcs/rfc1320.html
**	MD5		http://www.faqs.org/rfcs/rfc1321.html
**	SHA		https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
**	HMAC	https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.198-1.pdf
**			https://csrc.nist.gov/csrc/media/publications/fips/198/archive/
**				2002-03-06/documents/fips-198a.pdf
*/

/*
**	Transformation functions.
*/

char		*ft_base64(uint8_t *str, size_t len);
char		*ft_base64_url(uint8_t *str, size_t len);

uint8_t		*ft_unbase64(char *str, size_t *len);
uint8_t		*ft_unbase64_url(char *str, size_t *len);

uint32_t	ft_rotleft_uint32(uint32_t x, int c);
uint32_t	ft_rotright_uint32(uint32_t x, int c);
uint64_t	ft_rotleft_uint64(uint64_t x, int c);
uint64_t	ft_rotright_uint64(uint64_t x, int c);

/*
**	HAshing functions.
*/

char		*ft_md4(uint8_t *str, size_t len);
char		*ft_md5(uint8_t *str, size_t len);

char		*ft_sha1(uint8_t *msg, size_t len);
char		*ft_sha224(uint8_t *msg, size_t len);
char		*ft_sha256(uint8_t *msg, size_t len);
char		*ft_sha384(uint8_t *msg, size_t len);
char		*ft_sha512(uint8_t *msg, size_t len);
char		*ft_sha512_256(uint8_t *msg, size_t len);
char		*ft_sha512_224(uint8_t *msg, size_t len);

t_hmac		*ft_hmac_init(
						uint8_t *key,
						size_t len_key,
						char *(hash_f)(uint8_t *, size_t),
						size_t size_block);
char		*ft_hmac_process(
						t_hmac *hmac,
						uint8_t *msg,
						size_t len_msg);
void		ft_hmac_free(t_hmac **hmac);

/*
**	Prepare message with padding
*/

uint8_t		*ft_merkle_damgard_512_pad32_s32(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian);

uint8_t		*ft_merkle_damgard_512_pad64_s32(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian);

uint8_t		*ft_merkle_damgard_512_pad64_s64(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian);

uint8_t		*ft_merkle_damgard_1024_pad128_s64(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian);

uint8_t		*ft_merkle_damgard(
						t_merkle_damgard_config config,
						uint8_t *msg,
						size_t len,
						size_t *new_len);

/*
**	Des encryption
*/

t_des		*ft_des_new(
						uint64_t original_key,
						uint64_t iv,
						t_enc_action action,
						t_enc_mode mode);
void		ft_des_change_action(
						t_des *des,
						t_enc_action action);
void		ft_des_free(t_des **des);

uint8_t		*ft_des_process(
						t_des *des,
						uint8_t *msg,
						size_t size_in,
						size_t *size_out);

#endif
