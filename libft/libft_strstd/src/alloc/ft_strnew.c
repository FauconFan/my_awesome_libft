/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 14:43:34 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 10:35:44 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"
#include "libft_memory.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	index;

	index = 0;
	ft_memcheck((s = (char *)malloc(sizeof(char) * (size + 1))));
	while (index < size)
	{
		s[index] = 0;
		index++;
	}
	s[index] = 0;
	return (s);
}
