/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:48:38 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:51:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*d1;
	unsigned char	*d2;
	int				res;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		res = d1[index] - d2[index];
		if (res != 0)
			return (res);
		index++;
	}
	return (0);
}
