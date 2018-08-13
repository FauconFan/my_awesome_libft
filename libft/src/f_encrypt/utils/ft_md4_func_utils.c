/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md4_func_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:07:59 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 12:08:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_md4_f(uint32_t b, uint32_t c, uint32_t d)
{
	return (b & c) | (~b & d);
}

uint32_t	ft_md4_g(uint32_t b, uint32_t c, uint32_t d)
{
	return (b & c) | (b & d) | (c & d);
}

uint32_t	ft_md4_h(uint32_t b, uint32_t c, uint32_t d)
{
	return (b ^ c ^ d);
}
