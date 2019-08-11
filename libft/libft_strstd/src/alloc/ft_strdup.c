/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:58:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 10:34:30 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"
#include "libft_memory.h"

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
