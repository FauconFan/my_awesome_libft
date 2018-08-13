/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merkle_damgard_128.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:19:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 13:31:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t		*ft_merkle_damgard_64(char *msg, size_t *new_len)
{
	size_t		len;
	uint64_t	len_bits;
	uint8_t		*res;

	len = ft_strlen(msg);
	*new_len = len * 8 + 1;
	if (*new_len % 1024 > 896)
		*new_len += 1024 - 896;
	*new_len += 896 - (*new_len % 1024);
	*new_len /= 8;
	res = (uint8_t *)ft_strndup(msg, *new_len + 128);
	res[len] = 128;
	len_bits = 8 * len;
	ft_memcpy(res + *new_len, &len_bits, 8);
	return res;
}
