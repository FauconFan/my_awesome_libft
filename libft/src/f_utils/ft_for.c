/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:25:26 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 14:56:51 by jpriou           ###   ########.fr       */
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

void		ft_for(int min, int max, void (*f)())
{
	int		(*next)(int);

	if (min < max)
		next = incr;
	else
		next = decr;
	while (min != max)
	{
		f();
		min = next(min);
	}
}
