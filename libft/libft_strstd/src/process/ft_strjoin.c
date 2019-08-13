/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:22:47 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:36:35 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"
#include "libft_memory.h"

char					*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len_tot;
	char	*res;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_tot = ft_strlen(s1) + ft_strlen(s2);
	ft_memcheck((res = (char *)malloc(sizeof(char) * (len_tot + 1))));
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
