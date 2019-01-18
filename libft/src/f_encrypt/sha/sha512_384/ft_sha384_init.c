/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha384_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:16:23 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:08:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sha384	*ft_sha384_init(uint8_t *msg, size_t len)
{
	t_sha384	*sha384;

	ft_memcheck((sha384 = (t_sha384 *)malloc(sizeof(t_sha384))));
	sha384->msg = ft_merkle_damgard_1024_pad128_s64(
					msg,
					len,
					&(sha384->new_len),
					TRUE);
	sha384->hash[0] = 0xcbbb9d5dc1059ed8;
	sha384->hash[1] = 0x629a292a367cd507;
	sha384->hash[2] = 0x9159015a3070dd17;
	sha384->hash[3] = 0x152fecd8f70e5939;
	sha384->hash[4] = 0x67332667ffc00b31;
	sha384->hash[5] = 0x8eb44a8768581511;
	sha384->hash[6] = 0xdb0c2e0d64f98fa7;
	sha384->hash[7] = 0x47b5481dbefa4fa4;
	sha384->k = g_sha512_kk;
	return (sha384);
}

char		*ft_sha384_buildfinal_n_free(t_sha384 **sha)
{
	char	*res;

	ft_sprintf(&res, "%016llx%016llx%016llx%016llx%016llx%016llx",
				(*sha)->hash[0],
				(*sha)->hash[1],
				(*sha)->hash[2],
				(*sha)->hash[3],
				(*sha)->hash[4],
				(*sha)->hash[5]);
	ft_sha512_free(sha);
	return (res);
}
