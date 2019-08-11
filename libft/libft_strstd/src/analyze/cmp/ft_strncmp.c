/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:18:29 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:53:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

int		ft_strncmp(const char *s1, const char *s2, size_t size)
{
	if (size == 0)
		return (0);
	while (*(unsigned char *)s1 == *(unsigned char *)s2)
	{
		if (*(unsigned char *)s1 == 0)
			return (0);
		if (size == 1)
			return (*s1 - *s2);
		s1++;
		s2++;
		size--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
