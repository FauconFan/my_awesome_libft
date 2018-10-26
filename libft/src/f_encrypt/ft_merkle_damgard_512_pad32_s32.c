/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merkle_damgard_512_pad32_s32.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:19:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/26 14:50:02 by jpriou           ###   ########.fr       */
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
		custom_swap(res + index, res + index + 3);
		custom_swap(res + index + 1, res + index + 2);
		index += 4;
	}
}

uint8_t			*ft_merkle_damgard_512_pad32_s32(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian)
{
	uint32_t	len_bits;
	uint8_t		*res;

	*new_len = len * 8 + 1;
	if (*new_len % 512 > 480)
		*new_len += 512 - 480;
	*new_len += 480 - (*new_len % 512);
	*new_len /= 8;
	res = (uint8_t *)ft_memndup(msg, len, *new_len + 4);
	res[len] = 128;
	len_bits = 8 * len;
	if (little_endian)
		to_little_endian(res, *new_len);
	*new_len += 4;
	ft_memcpy(res + *new_len - 4, &len_bits, 4);
	return (res);
}
