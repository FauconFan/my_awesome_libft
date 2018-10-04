/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foriparam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:25:26 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 14:57:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	incr(int i)
{
	return (i + 1);
}

static int	decr(int i)
{
	return (i - 1);
}

void		ft_foriparam(int min, int max, void (*f)(void *, int i), void *p)
{
	int		(*next)(int);

	if (min < max)
		next = incr;
	else
		next = decr;
	while (min != max)
	{
		f(p, min);
		min = next(min);
	}
}
