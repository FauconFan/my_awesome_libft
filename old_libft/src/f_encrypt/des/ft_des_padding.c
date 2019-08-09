/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:36:29 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 11:50:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_des_build_msg(uint8_t *msg)
{
	size_t		j;
	uint64_t	res;

	j = 0;
	res = 0;
	while (j < 8)
	{
		res <<= 8;
		res |= (msg[j]);
		j++;
	}
	return (res);
}

void			ft_des_append_padding(uint8_t *msg, size_t remain)
{
	size_t		i;

	i = 0;
	while (i < remain)
	{
		msg[i] = remain;
		i++;
	}
}

void			ft_des_save_msg(uint8_t *res, uint64_t out)
{
	size_t	j;

	j = 0;
	while (j < 8)
	{
		res[j] = out >> (56 - 8 * j);
		j++;
	}
}
