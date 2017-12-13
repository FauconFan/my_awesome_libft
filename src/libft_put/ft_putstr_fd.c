/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:14:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:52:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *str, int fd)
{
	int	length;

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
