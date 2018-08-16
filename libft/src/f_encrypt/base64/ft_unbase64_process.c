/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbase64_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:32:26 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/15 20:53:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		validate_string(char *str, char base[64], char comp)
{
	int		len;
	int		index;

	len = ft_strlen(str);
	if (len % 4 != 0)
		return (-1);
	if (len == 0)
		return (0);
	index = 0;
	while (index < len - 2)
	{
		if (ft_str_contains_c(base, str[index]) == FALSE)
			return (-1);
		index++;
	}
	if (str[index] == comp)
	{
		if (str[index + 1] != comp)
			return (-1);
		return index;
	}
	if (ft_str_contains_c(base, str[index]) == FALSE)
		return (-1);
	index++;
	if (str[index] == comp)
		return (index);
	else if (ft_str_contains_c(base, str[index]))
		return (index + 1);
	return (-1);
}

char			get_rep6bits(char c, char base[64])
{
	int		res;

	res = 0;
	while (res < 64)
	{
		if (base[res] == c)
			return res;
		res++;
	}
	return (-1);
}

void			num2(char *str, char *res, char base[64])
{
	char	d[2];

	d[0] = get_rep6bits(str[0], base);
	d[1] = get_rep6bits(str[1], base);
	res[0] = (d[0] << 2) | (d[1] >> 4);
}

void			num3(char *str, char *res, char base[64])
{
	char	d[4];

	d[0] = get_rep6bits(str[0], base);
	d[1] = get_rep6bits(str[1], base);
	d[2] = get_rep6bits(str[2], base);
	res[0] = (d[0] << 2) | (d[1] >> 4);
	res[1] = (d[1] << 4) | (d[2] >> 2);
}

void			num4(char *str, char *res, char base[64])
{
	char	d[4];

	d[0] = get_rep6bits(str[0], base);
	d[1] = get_rep6bits(str[1], base);
	d[2] = get_rep6bits(str[2], base);
	d[3] = get_rep6bits(str[3], base);
	res[0] = (d[0] << 2) | (d[1] >> 4);
	res[1] = (d[1] << 4) | (d[2] >> 2);
	res[2] = (d[2] << 6) | d[3];
}

char			*ft_unbase64_process(char *str, char base[64], char comp)
{
	char	*res;
	int		real_size;
	size_t	i;
	size_t	j;

	real_size = validate_string(str, base, comp);
	if (real_size == -1)
		return (NULL);
	if (real_size % 4 == 0)
		res = ft_strnew((real_size / 4) * 3);
	else
		res = ft_strnew((real_size / 4) * 3 + ((real_size % 4) - 1));
	i = 0;
	j = 0;
	while (i + 3 < (size_t)real_size)
	{
		num4(str + i, res + j, base);
		i += 4;
		j += 3;
	}
	if (real_size % 4 == 2)
		num2(str + i, res + j, base);
	else if (real_size % 4 == 3)
		num3(str + i, res + j, base);
	return (res);
}
