/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:16:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 16:54:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sha512		*ft_sha512_init(char *msg)
{
	t_sha512	*sha512;

	ft_memcheck((sha512 = (t_sha512 *)malloc(sizeof(t_sha512))));
	sha512->msg = ft_merkle_damgard_1024_64(msg, &(sha512->new_len), TRUE);
	sha512->hash[0] = 0x6a09e667f3bcc908;
	sha512->hash[1] = 0xbb67ae8584caa73b;
	sha512->hash[2] = 0x3c6ef372fe94f82b;
	sha512->hash[3] = 0xa54ff53a5f1d36f1;
	sha512->hash[4] = 0x510e527fade682d1;
	sha512->hash[5] = 0x9b05688c2b3e6c1f;
	sha512->hash[6] = 0x1f83d9abfb41bd6b;
	sha512->hash[7] = 0x5be0cd19137e2179;
	sha512->k = g_sha512_kk;
	return sha512;
}

char		*ft_sha512_buildfinal_n_free(t_sha512 **sha)
{
	char	*res;

	ft_sprintf(&res, "%016llx%016llx%016llx%016llx%016llx%016llx%016llx%016llx",
				(*sha)->hash[0],
				(*sha)->hash[1],
				(*sha)->hash[2],
				(*sha)->hash[3],
				(*sha)->hash[4],
				(*sha)->hash[5],
				(*sha)->hash[6],
				(*sha)->hash[7]);
	ft_sha512_free(sha);
	return res;
}
