/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 22:18:42 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:52:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbrrecu(int nb, int fd)
{
	if (nb == 0)
		return ;
	ft_putnbrrecu(nb / 10, fd);
	ft_putchar_fd(-(nb % 10) + '0', fd);
}

void			ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (nb < 0)
		ft_putchar_fd('-', fd);
	else
		nb *= -1;
	ft_putnbrrecu(nb, fd);
}
