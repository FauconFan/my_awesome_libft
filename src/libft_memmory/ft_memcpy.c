/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:46:09 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:51:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d1;
	char	*d2;
	size_t	index;

	index = 0;
	d1 = (char *)dest;
	d2 = (char *)src;
	while (index < n)
	{
		d1[index] = d2[index];
		index++;
	}
	return (dest);
}
