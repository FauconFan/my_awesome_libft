/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nrt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 17:18:13 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/09 23:58:42 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

static double	core_nrt(double x, size_t n)
{
	double cand;
	double delta;

	cand = x;
	while (TRUE)
	{
		delta = ((x / ft_pow(cand, n - 1)) - cand) / n;
		cand += delta;
		if (ft_abs(delta) < PREC_DOUBLE)
			break ;
	}
	return (cand);
}

double			ft_nrt(double x, size_t n, short *rc)
{
	if (rc != NULL)
		*rc = (MATH_OK);
	if (n == 0)
		return (1);
	else if (n == 1)
		return (x);
	else if (ft_abs(x) <= PREC_DOUBLE)
		return (0);
	else if (x < 0 && n % 2 == 0)
	{
		if (rc != NULL)
			*rc = (MATH_NRT_EVEN_NEG);
		return (0);
	}
	return (core_nrt(x, n));
}
