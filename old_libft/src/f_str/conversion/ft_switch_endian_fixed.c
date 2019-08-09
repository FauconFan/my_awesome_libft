/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_endian_fixed.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:34:17 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/12 20:19:42 by jpriou           ###   ########.fr       */
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
	while (i < len / 4)
	{
		rk_l = 2 * i;
		rk_r = len - 2 - 2 * i;
		ft_swap(str + rk_l, str + rk_r);
		ft_swap(str + rk_l + 1, str + rk_r + 1);
		i++;
	}
}
