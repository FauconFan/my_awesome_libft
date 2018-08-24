/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 07:47:18 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/24 22:23:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_log_pos(double n, int len)
{
	if (n == 0)
		return (0);
	return (1 + ft_log_pos(n / len, len));
}

int				ft_logb(double n, int lengthbase)
{
	if (lengthbase <= 1)
		return (-1);
	else if (n == 0)
		return (1);
	else if (n < 0)
		return (-1);
	return (ft_log_pos(n, lengthbase));
}
