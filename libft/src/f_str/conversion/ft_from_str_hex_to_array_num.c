/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_from_str_hex_to_array_num.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:29:47 by jpriou            #+#    #+#             */
/*   Updated: 2018/09/19 19:30:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t		*ft_from_str_hex_to_array_num(char *str, size_t *len_res)
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
   return res;
}
