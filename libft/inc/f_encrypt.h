/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_encrypt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:50:41 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/15 21:09:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_ENCRYPT_H
#define F_ENCRYPT_H

#include "libft.h"
#include "inc/encrypt_utils/mdx.h"
#include "inc/encrypt_utils/sha.h"
#include "inc/encrypt_utils/base64.h"

/*
**	Source:
**
**	MD4		http://www.faqs.org/rfcs/rfc1320.html
**	MD5		http://www.faqs.org/rfcs/rfc1321.html
**	SHA		https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
*/

char		*ft_md4(char *str);
char		*ft_md5(char *str);

char		*ft_sha1(char *msg);
char		*ft_sha224(char *msg);
char		*ft_sha256(char *msg);
char		*ft_sha384(char *msg);
char		*ft_sha512(char *msg);
char		*ft_sha512_256(char *msg);
char		*ft_sha512_224(char *msg);

char		*ft_base64(char *str);
char		*ft_base64_url(char *str);

char		*ft_unbase64(char *str);
char		*ft_unbase64_url(char *str);

uint8_t		*ft_merkle_damgard_512_32(
						char *msg,
						size_t *new_len,
						t_bool little_endian);

uint8_t		*ft_merkle_damgard_512_64(
						char *msg,
						size_t *new_len,
						t_bool little_endian);

uint8_t		*ft_merkle_damgard_1024_64(
						char *msg,
						size_t *new_len,
						t_bool little_endian);

uint32_t	ft_rotleft_uint32(uint32_t x, int c);
uint32_t	ft_rotright_uint32(uint32_t x, int c);
uint64_t	ft_rotleft_uint64(uint64_t x, int c);
uint64_t	ft_rotright_uint64(uint64_t x, int c);

#endif
