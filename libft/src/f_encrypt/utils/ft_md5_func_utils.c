/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5_func_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:07:59 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 11:38:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_md5_f(uint32_t b, uint32_t c, uint32_t d)
{
	return (b & c) | (~b & d);
}

uint32_t	ft_md5_g(uint32_t b, uint32_t c, uint32_t d)
{
	return (b & d) | (c & ~d);
}

uint32_t	ft_md5_h(uint32_t b, uint32_t c, uint32_t d)
{
	return (b ^ c ^ d);
}

uint32_t	ft_md5_i(uint32_t b, uint32_t c, uint32_t d)
{
	return (c ^ (b | ~d));
}
