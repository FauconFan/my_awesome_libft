/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:18:22 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 14:19:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strrev(char *str)
{
	size_t	len;
	size_t	i;
	char	c;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = c;
		i++;
	}
}
