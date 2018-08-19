/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_process_block.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:25:20 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 13:08:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t		f(uint32_t r, uint64_t key)
{
	uint64_t	tmp1;
	uint32_t	tmp2;

	tmp1 = ft_des_apply_e(r) ^ key;
	tmp2 = ft_des_apply_s_tables(tmp1);
	return ft_des_apply_p(tmp2);
}

uint64_t			ft_des_process_block(
						uint64_t msg,
						uint64_t keys[16])
{
	uint32_t	l;
	uint32_t	r;
	uint32_t	r_tmp;
	uint64_t	tmp;
	size_t		i;

	msg = ft_des_apply_ip(msg);
	l = (uint32_t)((msg >> 32) & 0xffffffff);
	r = (uint32_t)(msg & 0xffffffff);
	i = 0;
	while (i < 16)
	{
		r_tmp = r;
		r = l ^ f(r, keys[i]);
		l = r_tmp;
		i++;
	}
	tmp = ft_des_apply_ip_min1((((uint64_t)r) << 32) | ((uint64_t)l));
	return (tmp);
}
