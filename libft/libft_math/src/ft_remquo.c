/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remquo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:57:56 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 17:00:11 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

double	ft_remquo(double x, double y)
{
	double yr;
	double tmp;

	yr = ft_dabs(y);
	tmp = x;
	while (tmp < 0)
		tmp += yr;
	while (tmp > yr)
		tmp -= yr;
	return (tmp);
}
