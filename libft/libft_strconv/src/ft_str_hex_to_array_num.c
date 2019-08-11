/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_hex_to_array_num.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:29:47 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 11:09:44 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strconv.h"
#include "libft_strstd.h"
#include "libft_ctype.h"

uint8_t		*ft_str_hex_to_array_num(char *str, size_t *len_res)
{
	uint8_t		*res;
	size_t		len;
	size_t		i;

	len = ft_strlen(str);
	res = (uint8_t *)ft_strnew(len / 2);
	i = 0;
	while (i < len)
	{
		if (i % 2 == 0)
			res[i / 2] |= ((int)ft_toxdigit(str[i])) << 4;
		else
			res[i / 2] |= ((int)ft_toxdigit(str[i]));
		i++;
	}
	*len_res = len / 2;
	return (res);
}
