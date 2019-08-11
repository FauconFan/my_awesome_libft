/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:15:33 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 14:53:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

size_t			ft_strlcat(char *dest, char *src, size_t nb)
{
	int					beg_i_d;
	int					index;
	size_t				length[2];
	size_t				res;

	length[0] = ft_strlen(dest);
	length[1] = ft_strlen(src);
	res = (nb < length[0]) ? length[1] + nb : length[1] + length[0];
	beg_i_d = nb - length[0];
	beg_i_d = (beg_i_d < 0) ? 0 : beg_i_d;
	index = 0;
	while (beg_i_d >= 0 && index < beg_i_d - 1 && src[index])
	{
		dest[length[0] + index] = src[index];
		index++;
	}
	dest[length[0] + index] = '\0';
	return (res);
}
