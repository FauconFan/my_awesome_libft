/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_func_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:07:59 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 13:19:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_md5_f(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & y) | (~x & z);
}

uint32_t	ft_md5_g(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & z) | (y & ~z);
}

uint32_t	ft_md5_h(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

uint32_t	ft_md5_i(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | ~z));
}
