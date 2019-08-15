/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 07:47:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/15 23:43:47 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

static int		ft_log_pos(double n, size_t len)
{
	if (n <= PREC_DOUBLE)
		return (0);
	return (1 + ft_log_pos(n / len, len));
}

int	ft_logb(double n, size_t lengthbase)
{
	if (lengthbase <= 1)
		return (-1);
	else if (n < 0)
		return (-1);
	else if (n <= PREC_DOUBLE)
		return (1);
	return (ft_log_pos(n, lengthbase));
}
