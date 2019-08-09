/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arccos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:35:11 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 14:11:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

double			ft_arccos(double x, short *rc)
{
	double sq3;

	if (rc != NULL)
		*rc = MATH_OK;
	if (x < -1 || x > 1)
	{
		if (rc != NULL)
			*rc = MATH_NOT_DEFINED;
		return (0);
	}
	else if (ft_abs(x) < PREC_DOUBLE)
		return (FT_PI / 2);
	else if (ft_abs(x - 1) < PREC_DOUBLE)
		return (0);
	else if (ft_abs(x + 1) < PREC_DOUBLE)
		return (-FT_PI / 2);
	sq3 = ft_sqrt(3, NULL);
	if (x > 2 - sq3)
		return (FT_PI / 6 + ft_arctan((x * sq3 - 1) / (sq3 + x)));
	return (x - x * x * x / 3 + x * x * x * x * x / 5);
}
