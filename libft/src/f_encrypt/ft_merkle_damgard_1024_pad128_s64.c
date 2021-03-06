/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merkle_damgard_1024_pad128_s64.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:19:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/28 11:18:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t			*ft_merkle_damgard_1024_pad128_s64(
						uint8_t *msg,
						size_t len,
						size_t *new_len,
						t_bool little_endian)
{
	t_merkle_damgard_config	config;

	config.size_blocks = 1024;
	config.padding_end = 128;
	config.size_size_end = 64;
	config.size_swap = 8;
	config.content_to_little_endian = little_endian;
	return (ft_merkle_damgard(config, msg, len, new_len));
}
