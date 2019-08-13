/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 21:57:41 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:35:29 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

const char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((const char *)s);
		s++;
	}
	if (c == '\0')
		return ((const char *)s);
	return (NULL);
}