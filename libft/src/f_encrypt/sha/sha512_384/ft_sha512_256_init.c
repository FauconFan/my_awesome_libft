/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512_256_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:16:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 17:30:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sha512		*ft_sha512_256_init(char *msg)
{
	t_sha512	*sha512;

	ft_memcheck((sha512 = (t_sha512 *)malloc(sizeof(t_sha512))));
	sha512->msg = ft_merkle_damgard_1024_64(msg, &(sha512->new_len), TRUE);
	sha512->hash[0] = 0x22312194fc2bf72c;
	sha512->hash[1] = 0x9f555fa3c84c64c2;
	sha512->hash[2] = 0x2393b86b6f53b151;
	sha512->hash[3] = 0x963877195940eabd;
	sha512->hash[4] = 0x96283ee2a88effe3;
	sha512->hash[5] = 0xbe5e1e2553863992;
	sha512->hash[6] = 0x2b0199fc2c85b8aa;
	sha512->hash[7] = 0x0eb72ddc81c52ca2;
	sha512->k = g_sha512_kk;
	return sha512;
}

char		*ft_sha512_256_buildfinal_n_free(t_sha512 **sha)
{
	char	*res;

	ft_sprintf(&res, "%016llx%016llx%016llx%016llx",
				(*sha)->hash[0],
				(*sha)->hash[1],
				(*sha)->hash[2],
				(*sha)->hash[3]);
	ft_sha512_free(sha);
	return res;
}
