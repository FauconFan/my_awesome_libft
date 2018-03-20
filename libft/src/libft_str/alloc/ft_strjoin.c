/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:22:47 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:54:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	len_tot;
	char			*res;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_tot = ft_strlen(s1) + ft_strlen(s2) + 1;
	ft_memcheck((res = (char *)malloc(sizeof(char) * len_tot)));
	len1 = 0;
	len2 = 0;
	while (s1[len1])
	{
		res[len1] = s1[len1];
		len1++;
	}
	while (s2[len2])
	{
		res[len1 + len2] = s2[len2];
		len2++;
	}
	res[len1 + len2] = 0;
	return (res);
}
