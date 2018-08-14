/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merkle_damgard_512_64.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:19:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 13:11:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		to_little_endian(uint8_t *res, size_t max)
{
	size_t	index;
	uint8_t	tmp;

	index = 0;
	while (index < max)
	{
		tmp = res[index];
		res[index] = res[index + 3];
		res[index + 3] = tmp;
		tmp = res[index + 1];
		res[index + 1] = res[index + 2];
		res[index + 2] = tmp;
		index += 4;
	}
}

uint8_t			*ft_merkle_damgard_512_64(
						char *msg,
						size_t *new_len,
						t_bool little_endian)
{
	size_t		len;
	uint64_t	len_bits;
	uint8_t		*res;

	len = ft_strlen(msg);
	*new_len = len * 8 + 1;
	if (*new_len % 512 > 448)
		*new_len += 512 - 448;
	*new_len += 448 - (*new_len % 512);
	*new_len /= 8;
	res = (uint8_t *)ft_strndup(msg, *new_len + 64);
	res[len] = 128;
	len_bits = 8 * len;
	if (little_endian)
		to_little_endian(res, *new_len);
	ft_memcpy(res + *new_len, &len_bits, 8);
	return res;
}
