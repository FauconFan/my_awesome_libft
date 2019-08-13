/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 09:47:26 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 18:19:55 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strlambda.h"

void	ft_striteri(const char *s, void (*f)(unsigned int, const char *))
{
	unsigned int	index;

	if (s == 0 || f == 0)
		return ;
	index = 0;
	while (*s)
	{
		f(index, s);
		index++;
		s++;
	}
}
