/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:54:15 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 17:00:03 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

double				ft_tan(double x, short *rc)
{
	double tmp;

	if (rc != NULL)
		*rc = MATH_OK;
	if (x < 0 || x > FT_PI)
		return (ft_tan(ft_remquo(x, FT_PI), rc));
	else if (x > 0.5 * FT_PI)
		return (-ft_tan(FT_PI - x, rc));
	else if (ft_dabs(x - FT_PI / 2) < PREC_DOUBLE)
	{
		if (rc != NULL)
			*rc = MATH_NOT_DEFINED;
		return (0);
	}
	else if (x > 0.25 * FT_PI)
		return (1 / ft_tan(FT_PI / 2 - x, rc));
	else if (x > 0.125 * FT_PI)
	{
		tmp = ft_tan(x / 2, rc);
		return (2 * tmp) / (1 - tmp * tmp);
	}
	tmp = x + x * x * x / 3;
	tmp += x * x * x * x * x * 2 / 15 + x * x * x * x * x * x * x * 17 / 315;
	return (tmp);
}
