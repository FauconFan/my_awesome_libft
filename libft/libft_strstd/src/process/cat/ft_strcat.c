/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:58:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:52:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	index[2];

	index[0] = 0;
	index[1] = 0;
	if (*src == 0)
		return (dest);
	while (dest[index[0]])
		index[0]++;
	while (src[index[1]])
	{
		dest[index[0] + index[1]] = src[index[1]];
		index[1]++;
	}
	dest[index[0] + index[1]] = 0;
	return (dest);
}
