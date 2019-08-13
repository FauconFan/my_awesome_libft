/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_endian.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:34:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:23:03 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

static void			ft_swap(uint8_t *s1, uint8_t *s2)
{
	uint8_t	c;

	c = *s1;
	*s1 = *s2;
	*s2 = c;
}

void				ft_switch_endian(uint8_t *str, size_t len)
{
	size_t	i;
	size_t	rk_l;
	size_t	rk_r;

	if (len % 2 == 1)
		return ;
	i = 0;
	while (i < len / 2)
	{
		rk_l = i;
		rk_r = len - 1 - i;
		ft_swap(str + rk_l, str + rk_r);
		i++;
	}
}