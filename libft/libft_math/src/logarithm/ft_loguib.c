/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loguib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 07:47:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/15 23:48:00 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

static unsigned int		ft_log_pos(unsigned int n, size_t len)
{
	if (n == 0)
		return (0);
	return (1 + ft_log_pos(n / len, len));
}

unsigned int			ft_loguib(unsigned int n, size_t lengthbase)
{
	if (lengthbase <= 1)
		return (0);
	else if (n == 0)
		return (1);
	return (ft_log_pos(n, lengthbase));
}
