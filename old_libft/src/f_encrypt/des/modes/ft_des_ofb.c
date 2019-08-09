/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_ofb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:55:13 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 22:37:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t				*ft_des_ofb_enc(
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
		out = ft_des_process_block(iv, des->key_n);
		iv = out;
		out = out ^ in;
		ft_des_save_msg(res + i, out);
		i += 8;
	}
	return (res);
}

uint8_t				*ft_des_ofb_dec(
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
		out = ft_des_process_block(iv, des->key_n);
		iv = out;
		out = out ^ in;
		ft_des_save_msg(res + i, out);
		i += 8;
	}
	return (res);
}
