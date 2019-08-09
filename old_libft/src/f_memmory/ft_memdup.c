/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:04:11 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 14:23:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(void *data, size_t len)
{
	void	*res;

	ft_memcheck((res = malloc(sizeof(void *) * len)));
	return (ft_memcpy(res, data, len));
}
