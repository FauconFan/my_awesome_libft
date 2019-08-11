/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_endian_fixed.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:34:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 10:53:25 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_swap(char *s1, char *s2)
{
	char	c;

	c = *s1;
	*s1 = *s2;
	*s2 = c;
}

void				ft_switch_endian_fixed(char *str, size_t len)
{
	size_t	i;
	size_t	rk_l;
	size_t	rk_r;

	if (len % 2 == 1 || ft_str_all(str, &ft_isxdigit) == FALSE)
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
