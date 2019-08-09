/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logullb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 07:47:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/09 23:58:09 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

static int		ft_log_pos(unsigned long long n, unsigned int len)
{
	if (n == 0)
		return (0);
	return (1 + ft_log_pos(n / len, len));
}

int				ft_logullb(unsigned long long n, int lengthbase)
{
	if (lengthbase <= 1)
		return (-1);
	else if (n == 0)
		return (1);
	return (ft_log_pos(n, (unsigned int)lengthbase));
}