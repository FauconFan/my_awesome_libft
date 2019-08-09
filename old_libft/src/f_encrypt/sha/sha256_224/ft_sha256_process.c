/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:53:13 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 12:09:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		process_rounds(t_sha256 *sh, uint32_t w[64])
{
	uint32_t	tmp1;
	uint32_t	tmp2;
	size_t		i;

	i = 0;
	while (i < 64)
	{
		tmp1 = sh->h
			+ ft_sha_sig_maj_256_1(sh->e)
			+ ft_sha_ch_32(sh->e, sh->f, sh->g)
			+ sh->k[i]
			+ w[i];
		tmp2 = ft_sha_sig_maj_256_0(sh->a)
			+ ft_sha_maj_32(sh->a, sh->b, sh->c);
		sh->h = sh->g;
		sh->g = sh->f;
		sh->f = sh->e;
		sh->e = sh->d + tmp1;
		sh->d = sh->c;
		sh->c = sh->b;
		sh->b = sh->a;
		sh->a = tmp1 + tmp2;
		i++;
	}
}

static void		build_msg_schedule(uint32_t *m, uint32_t w[64])
{
	size_t		i;

	i = -1;
	while (++i < 16)
		w[i] = m[i];
	i--;
	while (++i < 64)
		w[i] = ft_sha_sig_min_256_1(w[i - 2])
			+ w[i - 7]
			+ ft_sha_sig_min_256_0(w[i - 15])
			+ w[i - 16];
}

static void		process_block(t_sha256 *sh, size_t offset)
{
	uint32_t	*m;
	uint32_t	w[64];

	m = (uint32_t *)(sh->msg + offset);
	build_msg_schedule(m, w);
	sh->a = sh->hash[0];
	sh->b = sh->hash[1];
	sh->c = sh->hash[2];
	sh->d = sh->hash[3];
	sh->e = sh->hash[4];
	sh->f = sh->hash[5];
	sh->g = sh->hash[6];
	sh->h = sh->hash[7];
	process_rounds(sh, w);
	sh->hash[0] += sh->a;
	sh->hash[1] += sh->b;
	sh->hash[2] += sh->c;
	sh->hash[3] += sh->d;
	sh->hash[4] += sh->e;
	sh->hash[5] += sh->f;
	sh->hash[6] += sh->g;
	sh->hash[7] += sh->h;
}

void			ft_sha256_process(t_sha256 *sh)
{
	size_t	offset;

	offset = 0;
	while (offset < sh->new_len)
	{
		process_block(sh, offset);
		offset += 64;
	}
}
