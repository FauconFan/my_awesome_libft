/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbase64_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:32:26 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 14:52:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		validate_string(char *str, char base[64], char comp)
{
	int		len;
	int		index;

	len = ft_strlen(str);
	index = -1;
	if (len % 4 != 0)
		return (-1);
	if (len == 0)
		return (0);
	while (++index < len - 2)
	{
		if (ft_str_contains_c(base, str[index]) == FALSE)
			return (-1);
	}
	if (str[index] == comp)
		return ((str[index + 1] != comp) ? -1 : index);
	if (ft_str_contains_c(base, str[index]) == FALSE)
		return (-1);
	if (str[++index] == comp)
		return (index);
	else if (ft_str_contains_c(base, str[index]))
		return (index + 1);
	return (-1);
}

uint8_t			*ft_unbase64_process(
							char *str,
							size_t *len,
							char base[64],
							char comp)
{
	uint8_t	*res;
	int		real_size;
	size_t	index[2];

	real_size = validate_string(str, base, comp);
	*len = 0;
	if (real_size == -1)
		return (NULL);
	*len = (real_size / 4) * 3;
	if (real_size % 4 != 0)
		*len += ((real_size % 4) - 1);
	res = (uint8_t *)ft_strnew(*len);
	index[0] = 0;
	index[1] = 0;
	while (index[0] + 3 < (size_t)real_size)
	{
		dnum4(str + index[0], res + index[1], base);
		index[0] += 4;
		index[1] += 3;
	}
	if (real_size % 4 == 2)
		dnum2(str + index[0], res + index[1], base);
	else if (real_size % 4 == 3)
		dnum3(str + index[0], res + index[1], base);
	return (res);
}
