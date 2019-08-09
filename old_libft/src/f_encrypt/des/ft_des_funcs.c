/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:15:31 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 13:38:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_des_apply_e(uint32_t u)
{
	uint64_t	res;
	size_t		i;

	res = 0;
	i = 0;
	while (i < 48)
	{
		res |= ((uint64_t)(u >> ((32 - g_des_e[i])) & 1)) << (47 - i);
		i++;
	}
	return (res);
}

uint32_t		ft_des_apply_p(uint32_t u)
{
	uint32_t	res;
	size_t		i;

	res = 0;
	i = 0;
	while (i < 32)
	{
		res |= (u >> ((32 - g_des_p[i])) & 1) << (31 - i);
		i++;
	}
	return (res);
}

uint32_t		ft_des_apply_s_tables(uint64_t u)
{
	uint32_t	res;
	uint32_t	tmp;
	uint8_t		rk;
	size_t		i;

	res = 0;
	i = 0;
	while (i < 8)
	{
		tmp = (u >> (42 - 6 * i)) & 0b111111;
		rk = ((tmp & 1) | ((tmp >> 4) & 0b10)) << 4;
		rk |= (tmp >> 1) & 0xf;
		res |= g_des_s_tables[i][rk] << (28 - 4 * i);
		i++;
	}
	return (res);
}
