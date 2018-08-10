/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nrt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 17:18:13 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/02 20:39:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_nrt(double x, size_t n, short *rc)
{
	double cand;
	double delta;

	if (rc != NULL)
		*rc = MATH_OK;
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else if (x <= 0 && n % 2 == 0) {
		if (rc != NULL)
			*rc = MATH_NRT_EVEN_NEG;
		return 0;
	}
	else if (x == 0) {
		return 0;
	}
	cand = x;
	while (TRUE)
	{
		delta = ((x / ft_pow(cand, n - 1)) - cand) / n;
		cand += delta;
		if (ft_abs(delta) < PREC_DOUBLE)
			break ;
	}
	return cand;
}
