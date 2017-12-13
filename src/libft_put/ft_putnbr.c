/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 22:13:47 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:52:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbrrecu(int nb)
{
	if (nb == 0)
		return ;
	ft_putnbrrecu(nb / 10);
	ft_putchar(-(nb % 10) + '0');
}

void			ft_putnbr(int nb)
{
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	else if (nb < 0)
		ft_putchar('-');
	else
		nb *= -1;
	ft_putnbrrecu(nb);
}
