/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:21:42 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 09:56:04 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

static void  _print_hex(uint8_t d)
{
	unsigned char	c;

	c = (d < 10) ? '0' + d : 'A' + d - 10;
	write(1, &c, 1);
}

static void print_hex(uint8_t d)
{
	_print_hex(d / 16);
	_print_hex(d % 16);
}

void		ft_memprint(void *v, size_t len)
{
	size_t	index;
	uint8_t	*data;

	index = 0;
	data = (uint8_t *)v;
	while (index < len)
	{
		print_hex(*data);
		if (index % 16 == 15)
			write(1, "\n", 1);
		else if (index % 4 == 3)
			write(1, " ", 1);
		data++;
		index++;
	}
}
