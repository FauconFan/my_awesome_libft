/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:04:11 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 09:55:26 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void		*ft_memndup(void *data, size_t len, size_t n)
{
	char	*res;
	size_t	min;
	size_t	ecart;

	ft_memcheck((res = malloc(sizeof(void *) * n)));
	min = (len < n) ? len : n;
	ecart = (len < n) ? n : len;
	ecart -= min;
	res = ft_memcpy(res, data, min);
	ft_bzero(res + min, ecart);
	return (res);
}
