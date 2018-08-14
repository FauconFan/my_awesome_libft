/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:53:13 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 14:54:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		process_rounds(t_sha1 *sha1, uint32_t w[80])
{
	uint32_t	tmp;
	size_t		i;

	i = 0;
	while (i < 80)
	{
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
		i++;
	}
}

static void		process_block(t_sha1 *sha1, size_t offset)
{
	uint32_t	*m;
	uint32_t	w[80];
	size_t		i;

	m = (uint32_t *) (sha1->msg + offset);
	i = -1;
	while (++i < 16)
		w[i] = m[i];
	i--;
	while (++i < 80)
		w[i] = ft_rotleft_uint32((w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16]), 1);
	sha1->a = sha1->hash[0];
	sha1->b = sha1->hash[1];
	sha1->c = sha1->hash[2];
	sha1->d = sha1->hash[3];
	sha1->e = sha1->hash[4];
	process_rounds(sha1, w);
	sha1->hash[0] += sha1->a;
	sha1->hash[1] += sha1->b;
	sha1->hash[2] += sha1->c;
	sha1->hash[3] += sha1->d;
	sha1->hash[4] += sha1->e;
}

void			ft_sha1_process(t_sha1 *sha1)
{
	size_t	offset;

	offset = 0;
	while (offset < sha1->new_len)
	{
		process_block(sha1, offset);
		offset += 64;
	}
}
