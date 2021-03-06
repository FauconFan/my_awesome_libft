/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logllb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 07:47:18 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/24 22:26:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_log_pos(long long n, int len)
{
	if (n == 0)
		return (0);
	return (1 + ft_log_pos(n / len, len));
}

int				ft_logllb(long long n, int lengthbase)
{
	if (lengthbase <= 1)
		return (-1);
	else if (n == 0)
		return (1);
	else if (n < 0)
		return (-1);
	return (ft_log_pos(n, lengthbase));
}
