/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 17:25:38 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 14:06:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double x, size_t n)
{
	double res;

	if (n == 0)
		return (1);
	else if (n == 1)
		return (x);
	res = ft_pow(x, n / 2);
	res = res * res;
	if (n % 2 == 0)
		return (res);
	return (res * x);
}
