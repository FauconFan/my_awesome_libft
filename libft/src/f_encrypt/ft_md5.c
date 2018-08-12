/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:48:49 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/12 22:46:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_md5_update_fg(t_md5 *md5, int i, uint32_t *f, uint32_t *g)
{
	if (i < 16)
	{
		*f = (md5->b & md5->c) | ((~md5->b) & md5->d);
		*g = i;
	}
	else if (i < 32)
	{
		*f = (md5->d & md5->b) | ((~md5->d) & md5->c);
		*g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		*f = md5->b ^ md5->c ^ md5->d;
		*g = (3 * i + 5) % 16;
	}
	else
	{
		*f = md5->c ^ (md5->b | (~md5->d));
		*g = (7 * i) % 16;
	}
}

static void			process_word(t_md5 *md5, uint32_t *w)
{
	uint8_t			i;
	uint32_t		f;
	uint32_t		g;
	uint32_t		tmp;

	i = 0;
	while (i < 64)
	{
		ft_md5_update_fg(md5, i, &f, &g);
		tmp = md5->d;
		md5->d = md5->c;
		md5->c = md5->b;
		md5->b = md5->b + LEFTROTATE((md5->a + f + g_md5_k[i] + w[g]), g_md5_r[i]);
		md5->a = tmp;
		i++;
	}
}

static void			process_words(t_md5 *md5)
{
	size_t		offset;
	uint32_t	*w;

	offset = 0;
	while (offset < md5->new_len)
	{
		w = (uint32_t *) (md5->msg + offset);
		md5->a = md5->h[0];
		md5->b = md5->h[1];
		md5->c = md5->h[2];
		md5->d = md5->h[3];
		process_word(md5, w);
		md5->h[0] += md5->a;
		md5->h[1] += md5->b;
		md5->h[2] += md5->c;
		md5->h[3] += md5->d;
		offset += 64;
	}
}

char				*ft_md5(char *str)
{
	t_md5		*md5;
	char		*res = NULL;

	md5 = ft_md5_init(str);
	process_words(md5);
	ft_sprintf(&res, "%08x%08x%08x%08x", md5->h[0], md5->h[1], md5->h[2], md5->h[3]);
	ft_md5_free(&md5);
	ft_switch_endian_fixed(res, 8);
	ft_switch_endian_fixed(res + 8, 8);
	ft_switch_endian_fixed(res + 16, 8);
	ft_switch_endian_fixed(res + 24, 8);
	return res;
}
