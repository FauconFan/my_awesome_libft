/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remquo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:57:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/02 22:10:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_remquo(double x, double y)
{
	double yR;
	double tmp;

	yR = ft_abs(y);
	tmp = x;
	while (tmp < 0) {
		tmp += yR;
	}
	while (tmp > yR) {
		tmp -= yR;
	}
	return (tmp);
}
