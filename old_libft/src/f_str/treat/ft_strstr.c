/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:54:45 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:54:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		index;

	index = 0;
	if (*haystack == 0 && *needle == 0)
		return ((char *)haystack);
	if (*haystack == 0)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	if (*haystack == *needle)
	{
		while (haystack[index] == needle[index] && needle[index])
			index++;
		if (needle[index] == 0)
			return ((char *)haystack);
	}
	return (ft_strstr(haystack + 1, needle));
}
