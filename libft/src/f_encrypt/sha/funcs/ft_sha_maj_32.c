/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha_maj_32.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:59:25 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 14:08:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t		ft_sha_maj_32(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}
