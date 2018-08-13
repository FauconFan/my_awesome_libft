/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merkle_damgard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:19:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 11:27:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t		*ft_merkle_damgard(char *msg, size_t *new_len)
{
	size_t		len;
	uint32_t	len_bits;
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
	ft_memcpy(res + *new_len, &len_bits, 4);
	return res;
}
