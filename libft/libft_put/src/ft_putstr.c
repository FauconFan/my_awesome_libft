/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:13:25 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 09:59:44 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_put.h"

void		ft_putstr_fd(char const *str, int fd)
{
	size_t	length;

	length = 0;
	if (str == 0)
	{
		ft_putstr_fd("(null)", fd);
		return ;
	}
	while (str[length])
		length++;
	write(fd, str, length);
}

inline void	ft_putstr(char const *str)
{
	ft_putstr_fd(str, 1);
}
