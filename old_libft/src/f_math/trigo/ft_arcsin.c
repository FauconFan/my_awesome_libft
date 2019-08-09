/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arcsin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:25:15 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 14:11:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_arcsin(double x, short *rc)
{
	if (rc != NULL)
		*rc = MATH_OK;
	if (x < -1 || x > 1)
	{
		if (rc != NULL)
			*rc = MATH_NOT_DEFINED;
		return (0);
	}
	else if (ft_abs(x) < PREC_DOUBLE)
		return (0);
	else if (ft_abs(x - 1) < PREC_DOUBLE)
		return (FT_PI / 2);
	else if (ft_abs(x + 1) < PREC_DOUBLE)
		return (-FT_PI / 2);
	return (ft_arctan(x / (ft_sqrt(1 - x * x, NULL))));
}
