/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:15:31 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 10:29:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint64_t		ft_des_apply_ip_c(uint64_t u, uint8_t data[64])
{
	uint64_t	res;
	size_t		i;

	res = 0;
	i = 0;
	while (i < 64)
	{
		res |= ((u >> (64 - data[i])) & 1) << (63 - i);
		i++;
	}
	return res;
}

uint64_t			ft_des_apply_ip(uint64_t u)
{
	return (ft_des_apply_ip_c(u, g_des_ip));
}

uint64_t			ft_des_apply_ip_min1(uint64_t u)
{
	return (ft_des_apply_ip_c(u, g_des_ip_min1));
}
