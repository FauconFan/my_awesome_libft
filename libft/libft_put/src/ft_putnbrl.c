/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 11:03:12 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 09:59:56 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_put.h"

inline void		ft_putnbrl_fd(int c, int fd)
{
	ft_putnbr_fd(c, fd);
	ft_putchar_fd('\n', fd);
}

inline void		ft_putnbrl(int c)
{
	ft_putnbrl_fd(c, 1);
}
