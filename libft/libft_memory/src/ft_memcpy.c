/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:46:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 09:54:56 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d1;
	const char	*d2;
	size_t		index;

	index = 0;
	d1 = (char *)dest;
	d2 = (const char *)src;
	while (index < n)
	{
		d1[index] = d2[index];
		index++;
	}
	return (dest);
}
