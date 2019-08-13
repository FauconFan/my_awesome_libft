/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:33:35 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:59:52 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

static double		cos_compute(double x)
{
	size_t		level;
	double		res;
	double		mon;
	double		buffer;

	level = 0;
	res = 0;
	buffer = 1;
	while (TRUE)
	{
		mon = buffer / ft_fact(2 * level);
		res += mon * ((level % 2 == 0) ? 1 : -1);
		if (ft_dabs(mon) < PREC_DOUBLE)
			break ;
		buffer *= x * x;
		level++;
	}
	return (res);
}

double				ft_cos(double x)
{
	if (x < 0)
		return (ft_cos(-x));
	else if (x > 2 * FT_PI)
		return (ft_cos(ft_remquo(x, 2 * FT_PI)));
	else if (x > 1.5 * FT_PI)
		return (ft_cos(2 * FT_PI - x));
	else if (x > 0.5 * FT_PI)
		return (-ft_cos(FT_PI - x));
	else if (x > 0.25 * FT_PI)
		return (ft_sin(FT_PI / 2 - x));
	return (cos_compute(x));
}
