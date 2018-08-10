/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 21:25:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:58:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;
	size_t	index;

	index = 0;
	ft_memcheck((tmp = (char *)malloc(sizeof(char) * size)));
	while (index < size)
	{
		tmp[index] = 0;
		index++;
	}
	return ((void *)tmp);
}
