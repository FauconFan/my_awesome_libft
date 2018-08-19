/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_funcs3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:15:31 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 10:35:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t		ft_build_rl_key(uint64_t original_key, uint8_t data[28])
{
	uint32_t	res;
	size_t		i;

	res = 0;
	i = 0;
	while (i < 28)
	{
		res |= ((original_key >> (64 - data[i])) & 1) << (27 - i);
		i++;
	}
	return res;
}

uint32_t			ft_des_apply_pc1_left(uint64_t original_key)
{
	return ft_build_rl_key(original_key, g_des_pc1_left);
}

uint32_t			ft_des_apply_pc1_right(uint64_t original_key)
{
	return ft_build_rl_key(original_key, g_des_pc1_right);
}

uint64_t			ft_des_apply_pc2(uint64_t l, uint64_t r)
{
	uint64_t	res;
	size_t		j;

	res = 0;
	j = 0;
	while (j < 48)
	{
		if (g_des_pc2[j] <= 28)
		{
			res |= ((l >> (28 - g_des_pc2[j])) & 1) << (47 - j);
		}
		else
		{
			res |= ((r >> (56 - g_des_pc2[j])) & 1) << (47 - j);
		}
		j++;
	}
	return res;
}
