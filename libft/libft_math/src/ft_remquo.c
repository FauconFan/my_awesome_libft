/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remquo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:57:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 14:21:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

double	ft_remquo(double x, double y)
{
	double yr;
	double tmp;

	yr = ft_abs(y);
	tmp = x;
	while (tmp < 0)
		tmp += yr;
	while (tmp > yr)
		tmp -= yr;
	return (tmp);
}
