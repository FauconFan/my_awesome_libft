/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:15:30 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/02 21:29:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	sin_compute(double x)
{
	size_t	level;
	double	res;
	double	buffer;
	double	mon;

	level = 0;
	res = 0;
	buffer = x;
	while (TRUE)
	{
		mon = buffer / ((double)ft_fact(2 * level + 1));
		res += mon * ((level % 2 == 0) ? 1 : -1);
		if (ft_abs(mon) < PREC_DOUBLE)
			break ;
		buffer *= x * x;
		level++;
	}
	return res;
}

double			ft_sin(double x)
{
	if (x < 0)
		return - ft_sin(-x);
	else if (x > 2 * FT_PI)
		return ft_sin(ft_remquo(x, 2 * FT_PI));
	else if (x > FT_PI)
		return - ft_sin(x - FT_PI);
	else if (x > 0.5 * FT_PI)
		return ft_sin(FT_PI - x);
	else if (x > 0.25 * FT_PI)
		return ft_cos(FT_PI / 2 - x);
	return sin_compute(x);
}
