/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:49:37 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:51:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	index;

	s1 = (char *)dest;
	s2 = (char *)src;
	index = 0;
	while (index < n)
	{
		s1[index] = s2[index];
		if (s1[index] == (char)c)
			return ((void *)(s1 + index + 1));
		index++;
	}
	return (0);
}
