/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:17:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/17 13:24:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*build_str(uint64_t nu, size_t len)
{
	char		*res;
	char		*cpy;
	size_t		rank;
	size_t		index_nu;
	size_t		index_rank_actu;

	res = ft_strnew(len + (len / 8 - 1) * 3 + 1);
	cpy = res;
	rank = 0;
	index_nu = 0;
	while (rank < len / 8)
	{
		index_rank_actu = 0;
		while (index_rank_actu < 8)
		{
			*cpy = ((nu >> (len - 1 - index_nu)) & 1) ? '1' : '0';
			cpy++;
			index_nu++;
			if (index_rank_actu == 3)
			{
				*cpy = ' ';
				cpy++;
			}
			index_rank_actu++;
		}
		rank++;
		if (rank < len / 8)
		{
			*(cpy++) = ' ';
			*(cpy++) = ' ';
		}
	}
	return (res);
}

void				process_bits(
						va_list va,
						t_treat_data *data,
						t_pf_buffer *pf)
{
	char	*str;

	str = build_str(va_arg(va, uint64_t),
		ft_min(ft_max(8, (data->gabarit / 8) * 8), 64));
	pf_append(pf, str);
	ft_strdel(&str);
}
