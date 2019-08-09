/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md4_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 20:38:29 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:06:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t		g_md4_kk[] =
{
	0, 1, 2, 3,
	4, 5, 6, 7,
	8, 9, 10, 11,
	12, 13, 14, 15,
	0, 4, 8, 12,
	1, 5, 9, 13,
	2, 6, 10, 14,
	3, 7, 11, 15,
	0, 8, 4, 12,
	2, 10, 6, 14,
	1, 9, 5, 13,
	3, 11, 7, 15,
};

uint32_t		g_md4_ss[] =
{
	3, 7, 11, 19,
	3, 7, 11, 19,
	3, 7, 11, 19,
	3, 7, 11, 19,
	3, 5, 9, 13,
	3, 5, 9, 13,
	3, 5, 9, 13,
	3, 5, 9, 13,
	3, 9, 11, 15,
	3, 9, 11, 15,
	3, 9, 11, 15,
	3, 9, 11, 15,
};

uint32_t		g_md4_tt[] =
{
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 0,
	0x5A827999, 0x5A827999, 0x5A827999, 0x5A827999,
	0x5A827999, 0x5A827999, 0x5A827999, 0x5A827999,
	0x5A827999, 0x5A827999, 0x5A827999, 0x5A827999,
	0x5A827999, 0x5A827999, 0x5A827999, 0x5A827999,
	0x6ED9EBA1, 0x6ED9EBA1, 0x6ED9EBA1, 0x6ED9EBA1,
	0x6ED9EBA1, 0x6ED9EBA1, 0x6ED9EBA1, 0x6ED9EBA1,
	0x6ED9EBA1, 0x6ED9EBA1, 0x6ED9EBA1, 0x6ED9EBA1,
	0x6ED9EBA1, 0x6ED9EBA1, 0x6ED9EBA1, 0x6ED9EBA1,
};

t_mdx			*ft_md4_init(uint8_t *str, size_t len)
{
	t_mdx		*md4;

	ft_memcheck((md4 = (t_mdx *)malloc(sizeof(t_mdx))));
	md4->msg = ft_merkle_damgard_512_pad64_s64(
					str,
					len,
					&(md4->new_len),
					FALSE);
	md4->hash[0] = 0x67452301;
	md4->hash[1] = 0xefcdab89;
	md4->hash[2] = 0x98badcfe;
	md4->hash[3] = 0x10325476;
	md4->k = g_md4_kk;
	md4->s = g_md4_ss;
	md4->t = g_md4_tt;
	md4->f[0] = &ft_md4_f;
	md4->f[1] = &ft_md4_g;
	md4->f[2] = &ft_md4_h;
	md4->nb_rounds = 3;
	md4->add_b = FALSE;
	return (md4);
}
