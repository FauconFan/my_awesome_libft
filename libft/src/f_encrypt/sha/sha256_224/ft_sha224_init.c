/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:16:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/26 14:54:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sha224	*ft_sha224_init(uint8_t *msg, size_t len)
{
	t_sha224	*sha224;

	ft_memcheck((sha224 = (t_sha224 *)malloc(sizeof(t_sha224))));
	sha224->msg = ft_merkle_damgard_512_pad64_s32(msg, len, &(sha224->new_len), TRUE);
	sha224->hash[0] = 0xc1059ed8;
	sha224->hash[1] = 0x367cd507;
	sha224->hash[2] = 0x3070dd17;
	sha224->hash[3] = 0xf70e5939;
	sha224->hash[4] = 0xffc00b31;
	sha224->hash[5] = 0x68581511;
	sha224->hash[6] = 0x64f98fa7;
	sha224->hash[7] = 0xbefa4fa4;
	sha224->k = g_sha256_kk;
	return (sha224);
}

char		*ft_sha224_buildfinal_n_free(t_sha224 **sha)
{
	char	*res;

	ft_sprintf(&res, "%08x%08x%08x%08x%08x%08x%08x",
				(*sha)->hash[0],
				(*sha)->hash[1],
				(*sha)->hash[2],
				(*sha)->hash[3],
				(*sha)->hash[4],
				(*sha)->hash[5],
				(*sha)->hash[6]);
	ft_sha256_free(sha);
	return (res);
}
