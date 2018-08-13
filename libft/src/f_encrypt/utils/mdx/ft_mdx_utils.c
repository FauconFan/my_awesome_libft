/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mdx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:39:41 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 11:42:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*build_final_hash_after_process(t_mdx *mdx)
{
	char	*res;

	ft_sprintf(&res, "%08x%08x%08x%08x", mdx->h[0], mdx->h[1], mdx->h[2], mdx->h[3]);
	ft_switch_endian_fixed(res, 8);
	ft_switch_endian_fixed(res + 8, 8);
	ft_switch_endian_fixed(res + 16, 8);
	ft_switch_endian_fixed(res + 24, 8);
	return res;
}

void			ft_mdx_free(t_mdx **mdx)
{
	free((*mdx)->msg);
	free(*mdx);
	*mdx = NULL;
}
