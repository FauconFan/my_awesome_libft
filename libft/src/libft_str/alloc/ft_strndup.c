/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:50:10 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/21 08:28:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*res;
	size_t	index;

	res = ft_strnew(n);
	index = 0;
	while (index < n && s[index])
	{
		res[index] = s[index];
		index++;
	}
	return (res);
}
