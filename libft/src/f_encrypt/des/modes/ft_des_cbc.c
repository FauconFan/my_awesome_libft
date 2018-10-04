/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_cbc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:55:13 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 12:30:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t				*ft_des_cbc_enc(
						t_des *des,
						uint8_t *msg,
						size_t size)
{
	uint8_t		*res;
	uint64_t	iv;
	uint64_t	in;
	uint64_t	out;
	size_t		i;

	res = (uint8_t *)ft_strnew(size);
	i = 0;
	iv = des->iv;
	while (i < size)
	{
		in = ft_des_build_msg(msg + i);
		in = iv ^ in;
		out = ft_des_process_block(in, des->key_n);
		iv = out;
		ft_des_save_msg(res + i, out);
		i += 8;
	}
	return (res);
}

uint8_t				*ft_des_cbc_dec(
						t_des *des,
						uint8_t *msg,
						size_t size)
{
	uint8_t		*res;
	uint64_t	last_in;
	uint64_t	in;
	uint64_t	out;
	size_t		i;

	res = (uint8_t *)ft_strnew(size);
	i = 0;
	last_in = des->iv;
	while (i < size)
	{
		in = ft_des_build_msg(msg + i);
		out = ft_des_process_block(in, des->key_n_rev);
		out = out ^ last_in;
		last_in = in;
		ft_des_save_msg(res + i, out);
		i += 8;
	}
	return (res);
}
