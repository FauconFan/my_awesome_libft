/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512_224_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:16:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 12:18:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sha512	*ft_sha512_224_init(uint8_t *msg, size_t len)
{
	t_sha512	*sha512;

	ft_memcheck((sha512 = (t_sha512 *)malloc(sizeof(t_sha512))));
	sha512->msg = ft_merkle_damgard_1024_64(msg, len, &(sha512->new_len), TRUE);
	sha512->hash[0] = 0x8c3d37c819544da2;
	sha512->hash[1] = 0x73e1996689dcd4d6;
	sha512->hash[2] = 0x1dfab7ae32ff9c82;
	sha512->hash[3] = 0x679dd514582f9fcf;
	sha512->hash[4] = 0x0f6d2b697bd44da8;
	sha512->hash[5] = 0x77e36f7304c48942;
	sha512->hash[6] = 0x3f9d85a86a1d36c8;
	sha512->hash[7] = 0x1112e6ad91d692a1;
	sha512->k = g_sha512_kk;
	return (sha512);
}

char		*ft_sha512_224_buildfinal_n_free(t_sha512 **sha)
{
	char	*res;

	ft_sprintf(&res, "%016llx%016llx%016llx%016llx",
				(*sha)->hash[0],
				(*sha)->hash[1],
				(*sha)->hash[2],
				(*sha)->hash[3]);
	res[56] = '\0';
	ft_sha512_free(sha);
	return (res);
}
