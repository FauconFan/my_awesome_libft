/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_encrypt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:50:41 by jpriou            #+#    #+#             */
/*   Updated: 2018/09/19 19:27:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_ENCRYPT_H
#define F_ENCRYPT_H

#include "libft.h"
#include "inc/encrypt_utils/mdx.h"
#include "inc/encrypt_utils/sha.h"
#include "inc/encrypt_utils/base64.h"
#include "inc/encrypt_utils/des.h"
#include "inc/encrypt_utils/hmac.h"

/*
**	Source:
**
**	MD4		http://www.faqs.org/rfcs/rfc1320.html
**	MD5		http://www.faqs.org/rfcs/rfc1321.html
**	SHA		https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
**	HMAC	https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.198-1.pdf
**			https://csrc.nist.gov/csrc/media/publications/fips/198/archive/
* 				2002-03-06/documents/fips-198a.pdf
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

char		*ft_base64(uint8_t *str, size_t len);
char		*ft_base64_url(uint8_t *str, size_t len);

uint8_t		*ft_unbase64(char *str, size_t *len);
uint8_t		*ft_unbase64_url(char *str, size_t *len);

uint8_t		*ft_merkle_damgard_512_32(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian);

uint8_t		*ft_merkle_damgard_512_64(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian);

uint8_t		*ft_merkle_damgard_1024_64(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian);

uint32_t	ft_rotleft_uint32(uint32_t x, int c);
uint32_t	ft_rotright_uint32(uint32_t x, int c);
uint64_t	ft_rotleft_uint64(uint64_t x, int c);
uint64_t	ft_rotright_uint64(uint64_t x, int c);

t_hmac		*ft_hmac_init(
						uint8_t *key,
						size_t len_key,
						char *(hash_f)(uint8_t *, size_t),
						size_t size_block);
char		*ft_hmac_process(t_hmac *hmac, uint8_t *msg, size_t len_msg);
void		ft_hmac_free(t_hmac **hmac);

#endif
