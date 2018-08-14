/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:53:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 16:17:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_H
#define SHA_H

#include "libft.h"
#include "inc/encrypt_utils/sha1.h"
#include "inc/encrypt_utils/sha256_224.h"
#include "inc/encrypt_utils/sha512_384.h"

uint32_t			ft_sha_ch_32(uint32_t x, uint32_t y, uint32_t z);
uint32_t			ft_sha_maj_32(uint32_t x, uint32_t y, uint32_t z);
uint32_t			ft_sha_parity_32(uint32_t x, uint32_t y, uint32_t z);

uint64_t			ft_sha_ch_64(uint64_t x, uint64_t y, uint64_t z);
uint64_t			ft_sha_maj_64(uint64_t x, uint64_t y, uint64_t z);

uint32_t			ft_sha_sig_maj_256_0(uint32_t x);
uint32_t			ft_sha_sig_maj_256_1(uint32_t x);
uint32_t			ft_sha_sig_min_256_0(uint32_t x);
uint32_t			ft_sha_sig_min_256_1(uint32_t x);

uint64_t			ft_sha_sig_maj_512_0(uint64_t x);
uint64_t			ft_sha_sig_maj_512_1(uint64_t x);
uint64_t			ft_sha_sig_min_512_0(uint64_t x);
uint64_t			ft_sha_sig_min_512_1(uint64_t x);

#endif
