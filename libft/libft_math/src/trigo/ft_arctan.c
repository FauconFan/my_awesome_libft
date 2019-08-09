/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arctan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:44:24 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 14:08:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

double		ft_arctan(double x)
{
	double sq3;

	if (x < 0)
		return (ft_arctan(-x));
	else if (ft_abs(x) < PREC_DOUBLE)
		return (0);
	else if (x > 1)
		return (FT_PI / 2 - ft_arctan(1 / x));
	sq3 = ft_sqrt(3, NULL);
	if (x > 2 - sq3)
		return (FT_PI / 6 + ft_arctan((x * sq3 - 1) / (sq3 + x)));
	return (x - x * x * x / 3 + x * x * x * x * x / 5);
}
