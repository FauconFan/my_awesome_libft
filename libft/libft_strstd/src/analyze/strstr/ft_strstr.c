/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:54:45 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:32:18 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

const char	*ft_strstr(const char *haystack, const char *needle)
{
	int		index;

	index = 0;
	if (*haystack == 0 && *needle == 0)
		return ((const char *)haystack);
	if (*haystack == 0)
		return (NULL);
	if (*needle == 0)
		return ((const char *)haystack);
	if (*haystack == *needle)
	{
		while (haystack[index] == needle[index] && needle[index])
			index++;
		if (needle[index] == 0)
			return ((const char *)haystack);
	}
	return (ft_strstr(haystack + 1, needle));
}
