/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 11:50:37 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 09:54:20 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

const void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*d;

	d = (const char *)s;
	while (n)
	{
		if (*d == (char)c)
			return ((const void *)d);
		d++;
		n--;
	}
	return (0);
}
