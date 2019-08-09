/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:16:23 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:07:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sha256	*ft_sha256_init(uint8_t *msg, size_t len)
{
	t_sha256	*sha256;

	ft_memcheck((sha256 = (t_sha256 *)malloc(sizeof(t_sha256))));
	sha256->msg = ft_merkle_damgard_512_pad64_s32(
					msg,
					len,
					&(sha256->new_len),
					TRUE);
	sha256->hash[0] = 0x6a09e667;
	sha256->hash[1] = 0xbb67ae85;
	sha256->hash[2] = 0x3c6ef372;
	sha256->hash[3] = 0xa54ff53a;
	sha256->hash[4] = 0x510e527f;
	sha256->hash[5] = 0x9b05688c;
	sha256->hash[6] = 0x1f83d9ab;
	sha256->hash[7] = 0x5be0cd19;
	sha256->k = g_sha256_kk;
	return (sha256);
}

char		*ft_sha256_buildfinal_n_free(t_sha256 **sha)
{
	char	*res;

	ft_sprintf(&res, "%08x%08x%08x%08x%08x%08x%08x%08x",
				(*sha)->hash[0],
				(*sha)->hash[1],
				(*sha)->hash[2],
				(*sha)->hash[3],
				(*sha)->hash[4],
				(*sha)->hash[5],
				(*sha)->hash[6],
				(*sha)->hash[7]);
	ft_sha256_free(sha);
	return (res);
}
