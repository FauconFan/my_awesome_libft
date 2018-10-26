/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merkle_damgard_1024_pad64_s64.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:19:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/26 14:51:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		custom_swap(uint8_t *t1, uint8_t *t2)
{
	uint8_t	tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

static void		to_little_endian(uint8_t *res, size_t max)
{
	size_t	index;

	index = 0;
	while (index < max)
	{
		custom_swap(res + index, res + index + 7);
		custom_swap(res + index + 1, res + index + 6);
		custom_swap(res + index + 2, res + index + 5);
		custom_swap(res + index + 3, res + index + 4);
		index += 8;
	}
}

uint8_t			*ft_merkle_damgard_1024_pad64_s64(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian)
{
	uint64_t	len_bits;
	uint8_t		*res;

	*new_len = len * 8 + 1;
	if (*new_len % 1024 > 960)
		*new_len += 1024 - 960;
	*new_len += 960 - (*new_len % 1024);
	*new_len /= 8;
	res = (uint8_t *)ft_memndup(msg, len, *new_len + 4);
	res[len] = 128;
	len_bits = 8 * len;
	if (little_endian)
		to_little_endian(res, *new_len);
	*new_len += 8;
	ft_memcpy(res + *new_len - 8, &len_bits, 8);
	return (res);
}
