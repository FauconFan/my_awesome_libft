/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:48:38 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 09:54:42 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					index;
	const unsigned char		*d1;
	const unsigned char		*d2;
	int						res;

	d1 = (const unsigned char *)s1;
	d2 = (const unsigned char *)s2;
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
