/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:52:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 13:13:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sha1(char *msg)
{
	t_sha	*sha1;
	char	*res;

	sha1 = ft_sha1_init(msg);

	size_t		offset;
	uint32_t	*m;
	uint32_t	w[80];
	uint32_t	tmp;

	offset = 0;
	while (offset < sha1->new_len)
	{
		m = (uint32_t *) (sha1->msg + offset);
		for (size_t i = 0; i < 80; i++) {
			if (i < 16)
				w[i] = m[i];
			else
				w[i] = ft_rotleft_uint32((w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16]), 1);
		}
		sha1->a = sha1->hash[0];
		sha1->b = sha1->hash[1];
		sha1->c = sha1->hash[2];
		sha1->d = sha1->hash[3];
		sha1->e = sha1->hash[4];
		for (size_t i = 0; i < 80; i++) {
			tmp = ft_rotleft_uint32(sha1->a, 5)
				+ sha1->func_sha1[i / 20](sha1->b, sha1->c, sha1->d)
				+ sha1->e
				+ sha1->k[i / 20]
				+ w[i];
			sha1->e = sha1->d;
			sha1->d = sha1->c;
			sha1->c = ft_rotleft_uint32(sha1->b, 30);
			sha1->b = sha1->a;
			sha1->a = tmp;
		}
		sha1->hash[0] += sha1->a;
		sha1->hash[1] += sha1->b;
		sha1->hash[2] += sha1->c;
		sha1->hash[3] += sha1->d;
		sha1->hash[4] += sha1->e;
		offset += 64;
	}

	res = ft_sha1_buildfinal_n_free(&sha1);
	return res;
}
