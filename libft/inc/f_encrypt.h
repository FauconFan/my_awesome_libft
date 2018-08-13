/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_encrypt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:50:41 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 13:39:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_ENCRYPT_H
#define F_ENCRYPT_H

#include "libft.h"
#include "inc/encrypt_utils/mdx.h"

/*
**	Source:
**
**	MD4		http://www.faqs.org/rfcs/rfc1320.html
**	MD5		http://www.faqs.org/rfcs/rfc1321.html
**	SHA		https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
*/

char		*ft_md5(char *str);
char		*ft_md4(char *str);

uint8_t		*ft_merkle_damgard_32(char *msg, size_t *new_len);
uint8_t		*ft_merkle_damgard_64(char *msg, size_t *new_len);

uint32_t	ft_rotleft_uint32(uint32_t x, int c);
uint32_t	ft_rotright_uint32(uint32_t x, int c);
uint64_t	ft_rotleft_uint64(uint64_t x, int c);
uint64_t	ft_rotright_uint64(uint64_t x, int c);

#endif
