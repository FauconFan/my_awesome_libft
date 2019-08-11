/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:50:37 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:57:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*d;

	d = (char *)s;
	while (n)
	{
		if (*d == (char)c)
			return ((void *)d);
		d++;
		n--;
	}
	return (0);
}
