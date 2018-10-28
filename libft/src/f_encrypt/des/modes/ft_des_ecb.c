/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_ecb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:55:13 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/28 09:47:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool				ft_des_ecb_need_iv(void)
{
	return (FALSE);
}

static uint8_t		*ft_des_ecb(
						uint8_t *msg,
						size_t size,
						uint64_t keys[16])
{
	uint8_t		*res;
	uint64_t	in;
	uint64_t	out;
	size_t		i;

	res = (uint8_t *)ft_strnew(size);
	i = 0;
	while (i < size)
	{
		in = ft_des_build_msg(msg + i);
		out = ft_des_process_block(in, keys);
		ft_des_save_msg(res + i, out);
		i += 8;
	}
	return (res);
}

uint8_t				*ft_des_ecb_enc(
						t_des *des,
						uint8_t *msg,
						size_t size)
{
	return (ft_des_ecb(msg, size, des->key_n));
}

uint8_t				*ft_des_ecb_dec(
						t_des *des,
						uint8_t *msg,
						size_t size)
{
	return (ft_des_ecb(msg, size, des->key_n_rev));
}
