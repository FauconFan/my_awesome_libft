/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:51:39 by jpriou            #+#    #+#             */
/*   Updated: 2018/09/19 17:53:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*d;
	size_t	index;

	index = 0;
	d = (char *)s;
	while (index < n)
	{
		d[index] = (char)c;
		index++;
	}
	return (s);
}
