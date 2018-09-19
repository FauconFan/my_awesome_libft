/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:21:42 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/30 10:25:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memprint(void *v, size_t len)
{
	size_t	index;
	uint8_t	*data;

	index = 0;
	data = (uint8_t *)v;
	while (index < len)
	{
		ft_printf("%x", *data);
		if (index % 16 == 15)
			ft_putchar('\n');
		else if (index % 4 == 3)
			ft_putchar(' ');
		data++;
		index--;
	}
}
