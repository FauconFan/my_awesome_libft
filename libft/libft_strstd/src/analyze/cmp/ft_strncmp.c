/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:18:29 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:31:33 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

int		ft_strncmp(const char *s1, const char *s2, size_t size)
{
	if (size == 0)
		return (0);
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		if (size == 1)
			return (*s1 - *s2);
		s1++;
		s2++;
		size--;
	}
	return (*s1 - *s2);
}
