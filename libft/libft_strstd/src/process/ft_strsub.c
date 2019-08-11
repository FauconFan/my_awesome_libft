/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:23:19 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 10:36:13 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"
#include "libft_memory.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	index;

	if (s == 0)
		return (0);
	index = 0;
	ft_memcheck((res = (char *)malloc(sizeof(char) * (len + 1))));
	while (index < len)
	{
		res[index] = s[(size_t)start + index];
		index++;
	}
	res[index] = 0;
	return (res);
}
