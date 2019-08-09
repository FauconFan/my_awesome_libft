/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:18:44 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:52:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *str)
{
	int		length;

	length = 0;
	if (str == 0)
	{
		ft_putendl("(null)");
		return ;
	}
	while (str[length])
		length++;
	write(1, str, length);
	write(1, "\n", 1);
}
