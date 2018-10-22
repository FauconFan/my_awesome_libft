/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbase64_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:32:26 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/22 16:51:02 by jpriou           ###   ########.fr       */
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

static char		*pre_treatment(char *str, char base[65], int *real_size)
{
	char	*cpy;
	char	*cpy_base;
	size_t	len;

	cpy_base = ft_strndup(base, 64);
	len = ft_strlen(str);
	while (len > 0 && ft_iswhitespace(str[len - 1]))
		len--;
	cpy = ft_strndup(str, len);
	*real_size = validate_string(cpy, cpy_base, base[64]);
	ft_strdel(&cpy_base);
	return (cpy);
}

static uint8_t	*process_core(
						char *str,
						size_t len,
						size_t real_size,
						char base[65])
{
	size_t	index[2];
	uint8_t	*res;

	res = (uint8_t *)ft_strnew(len);
	index[0] = 0;
	index[1] = 0;
	while (index[0] + 3 < real_size)
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

uint8_t			*ft_unbase64_process(
							char *str,
							size_t *len,
							char base[65])
{
	uint8_t	*res;
	int		real_size;
	char	*cpy;

	cpy = pre_treatment(str, base, &real_size);
	*len = 0;
	if (real_size == -1)
		return (NULL);
	*len = (real_size / 4) * 3;
	if (real_size % 4 != 0)
		*len += ((real_size % 4) - 1);
	res = process_core(cpy, *len, (size_t)real_size, base);
	ft_strdel(&cpy);
	return (res);
}
