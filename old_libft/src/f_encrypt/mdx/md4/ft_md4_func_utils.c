/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md4_func_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:07:59 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 13:18:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_md4_f(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & y) | (~x & z);
}

uint32_t	ft_md4_g(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & y) | (x & z) | (y & z);
}

uint32_t	ft_md4_h(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}
