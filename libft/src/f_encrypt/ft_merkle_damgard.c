/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merkle_damgard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:19:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/28 11:21:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void			custom_swap(uint8_t *t1, uint8_t *t2)
{
	uint8_t	tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

static inline void			to_little_endian(
								uint8_t *res,
								size_t max,
								size_t size_swap)
{
	size_t	index;
	size_t	subindex;

	index = 0;
	while (index < max)
	{
		subindex = 0;
		while (subindex < size_swap / 2)
		{
			custom_swap(
				res + index + subindex,
				res + index + size_swap - 1 - subindex);
			subindex++;
		}
		index += size_swap;
	}
}

static inline t_bool		check_consistency(t_merkle_damgard_config config)
{
	if (config.size_blocks % 8 == 0
		&& config.padding_end % 8 == 0
		&& config.size_size_end % 8 == 0
		&& config.size_swap % 2 == 0
		&& config.padding_end >= config.size_size_end
		&& config.size_blocks > config.padding_end)
		return (TRUE);
	return (FALSE);
}

uint8_t						*ft_merkle_damgard(
						t_merkle_damgard_config config,
						uint8_t *msg,
						size_t len,
						size_t *new_len)
{
	uint64_t	len_bits;
	uint8_t		*res;
	size_t		size_pre_block;

	if (check_consistency(config) == FALSE)
		return (NULL);
	*new_len = len * 8 + 1;
	size_pre_block = config.size_blocks - config.padding_end;
	if (*new_len % config.size_blocks > size_pre_block)
		*new_len += config.padding_end;
	*new_len += size_pre_block - (*new_len % config.size_blocks);
	*new_len /= 8;
	res = (uint8_t *)ft_memndup(msg, len, *new_len + config.padding_end / 8);
	res[len] = 128;
	len_bits = 8 * len;
	if (config.content_to_little_endian)
		to_little_endian(res, *new_len, config.size_swap);
	*new_len += config.padding_end / 8;
	ft_memcpy(res + *new_len - config.size_size_end / 8,
		&len_bits, config.size_size_end / 8);
	return (res);
}
