/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:58:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:56:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*res;

	len = 0;
	res = 0;
	while (s[len])
		len++;
	ft_memcheck((res = (char *)malloc(sizeof(char) * (len + 1))));
	len = 0;
	while (s[len])
	{
		res[len] = s[len];
		len++;
	}
	res[len] = 0;
	return (res);
}
