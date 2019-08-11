/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 22:13:47 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 10:00:07 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_put.h"

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

inline void		ft_putnbr(int nb)
{
	ft_putnbr_fd(nb, 1);
}
