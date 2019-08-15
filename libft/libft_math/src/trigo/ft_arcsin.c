/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arcsin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 22:25:15 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/15 23:55:58 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

double			ft_arcsin(double x, t_math_res *rc)
{
	if (rc != NULL)
		*rc = MATH_OK;
	if (x < -1 || x > 1)
	{
		if (rc != NULL)
			*rc = MATH_NOT_DEFINED;
		return (0);
	}
	else if (ft_dabs(x) < PREC_DOUBLE)
		return (0);
	else if (ft_dabs(x - 1) < PREC_DOUBLE)
		return (FT_PI / 2);
	else if (ft_dabs(x + 1) < PREC_DOUBLE)
		return (-FT_PI / 2);
	return (ft_arctan(x / (ft_sqrt(1 - x * x, NULL))));
}
