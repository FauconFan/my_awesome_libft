/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mdx_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:36:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 13:11:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	MD4		http://www.faqs.org/rfcs/rfc1320.html
**	MD5		http://www.faqs.org/rfcs/rfc1321.html
*/

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
		w = (uint32_t *) (mdx->msg + offset);
		mdx->a = mdx->h[0];
		mdx->b = mdx->h[1];
		mdx->c = mdx->h[2];
		mdx->d = mdx->h[3];
		process_word(mdx, w);
		mdx->h[0] += mdx->a;
		mdx->h[1] += mdx->b;
		mdx->h[2] += mdx->c;
		mdx->h[3] += mdx->d;
		offset += 64;
	}
}
