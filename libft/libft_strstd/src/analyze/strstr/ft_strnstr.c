/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:58:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:32:31 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

const char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;

	index = 0;
	if (len == 0)
		return (NULL);
	if (*haystack == 0)
		return (NULL);
	if (*needle == 0)
		return ((const char *)haystack);
	if (*haystack == *needle)
	{
		while (haystack[index] == needle[index]
			&& needle[index]
			&& index != len)
			index++;
		if (needle[index] == 0)
			return ((const char *)haystack);
	}
	return (ft_strnstr(haystack + 1, needle, len - 1));
}
