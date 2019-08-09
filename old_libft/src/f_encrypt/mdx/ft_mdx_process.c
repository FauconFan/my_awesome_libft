/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mdx_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:36:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 12:28:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			process_word(t_mdx *mdx, uint32_t *w)
{
	uint8_t			i;
	uint32_t		f;
	uint32_t		cand;
	uint32_t		tmp;

	i = 0;
	while (i < mdx->nb_rounds * 16)
	{
		f = mdx->f[i / 16](mdx->b, mdx->c, mdx->d);
		cand = mdx->a + f + w[mdx->k[i]] + mdx->t[i];
		cand = ft_rotleft_uint32(cand, mdx->s[i]);
		if (mdx->add_b)
			cand += mdx->b;
		tmp = mdx->d;
		mdx->d = mdx->c;
		mdx->c = mdx->b;
		mdx->b = cand;
		mdx->a = tmp;
		i++;
	}
}

void				process_mdx(t_mdx *mdx)
{
	size_t		offset;
	uint32_t	*w;

	offset = 0;
	while (offset < mdx->new_len)
	{
		w = (uint32_t *)(mdx->msg + offset);
		mdx->a = mdx->hash[0];
		mdx->b = mdx->hash[1];
		mdx->c = mdx->hash[2];
		mdx->d = mdx->hash[3];
		process_word(mdx, w);
		mdx->hash[0] += mdx->a;
		mdx->hash[1] += mdx->b;
		mdx->hash[2] += mdx->c;
		mdx->hash[3] += mdx->d;
		offset += 64;
	}
}
