/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:04:11 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/30 10:09:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memndup(void *data, size_t len, size_t n)
{
	void	*res;
	size_t	min;
	size_t	ecart;

	ft_memcheck((res = malloc(sizeof(void *) * n)));
	min = ft_min(len, n);
	ecart = ft_max(len, n) - min;
	res = ft_memcpy(res, data, min);
	ft_bzero(res + min, ecart);
	return res;
}
