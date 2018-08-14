/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:16:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 13:12:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	g_sha1_kk[] = {0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6};

t_sha		*ft_sha1_init(char *msg)
{
	t_sha	*sha1;

	ft_memcheck((sha1 = (t_sha *)malloc(sizeof(t_sha))));
	sha1->msg = ft_merkle_damgard_512_32(msg, &(sha1->new_len), TRUE);
	sha1->hash[0] = 0x67452301;
	sha1->hash[1] = 0xefcdab89;
	sha1->hash[2] = 0x98badcfe;
	sha1->hash[3] = 0x10325476;
	sha1->hash[4] = 0xc3d2e1f0;
	sha1->k = g_sha1_kk;
	sha1->func_sha1[0] = &ft_sha_ch_32;
	sha1->func_sha1[1] = &ft_sha_parity_32;
	sha1->func_sha1[2] = &ft_sha_maj_32;
	sha1->func_sha1[3] = &ft_sha_parity_32;
	return sha1;
}

char		*ft_sha1_buildfinal_n_free(t_sha **sha)
{
	char	*res;

	ft_sprintf(&res, "%08x%08x%08x%08x%08x",
				(*sha)->hash[0],
				(*sha)->hash[1],
				(*sha)->hash[2],
				(*sha)->hash[3],
				(*sha)->hash[4]);
	ft_sha_free(sha);
	return res;
}
