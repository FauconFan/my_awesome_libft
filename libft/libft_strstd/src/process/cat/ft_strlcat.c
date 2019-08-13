/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:15:33 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:35:06 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

size_t			ft_strlcat(char *dest, char *src, size_t nb)
{
	int					beg_i_d;
	size_t				index;
	size_t				length[2];
	size_t				res;

	length[0] = ft_strlen(dest);
	length[1] = ft_strlen(src);
	res = (nb < length[0]) ? length[1] + nb : length[1] + length[0];
	beg_i_d = (int)nb - (int)length[0];
	beg_i_d = (beg_i_d < 0) ? 0 : beg_i_d;
	index = 0;
	while (beg_i_d >= 0 && index < (unsigned int)beg_i_d - 1 && src[index])
	{
		dest[length[0] + index] = src[index];
		index++;
	}
	dest[length[0] + index] = '\0';
	return (res);
}
