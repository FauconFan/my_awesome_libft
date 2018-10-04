/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:32:26 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 13:56:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		num1(uint8_t *str, char *res, char base[64], char comp)
{
	uint8_t	d[2];

	d[0] = (str[0] >> 2) & 0b111111;
	d[1] = ((str[0] & 0b11) << 4);
	res[0] = base[d[0]];
	res[1] = base[d[1]];
	res[2] = comp;
	res[3] = comp;
}

static void		num2(uint8_t *str, char *res, char base[64], char comp)
{
	uint8_t	d[3];

	d[0] = (str[0] >> 2) & 0b111111;
	d[1] = ((str[0] & 0b11) << 4) | ((str[1] >> 4) & 0b1111);
	d[2] = ((str[1] & 0b1111) << 2);
	res[0] = base[d[0]];
	res[1] = base[d[1]];
	res[2] = base[d[2]];
	res[3] = comp;
}

static void		num3(uint8_t *str, char *res, char base[64])
{
	uint8_t	d[4];

	d[0] = (str[0] >> 2) & 0b111111;
	d[1] = ((str[0] & 0b11) << 4) | ((str[1] >> 4) & 0b1111);
	d[2] = ((str[1] & 0b1111) << 2) | ((str[2] >> 6) & 0b11);
	d[3] = (str[2] & 0b111111);
	res[0] = base[d[0]];
	res[1] = base[d[1]];
	res[2] = base[d[2]];
	res[3] = base[d[3]];
}

char			*ft_base64_process(
							uint8_t *str,
							size_t len,
							char base[64],
							char comp)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = ft_strnew(((len + 2) / 3) * 4);
	i = 0;
	j = 0;
	while (i + 2 < len)
	{
		num3(str + i, res + j, base);
		i += 3;
		j += 4;
	}
	if (len % 3 == 2)
		num2(str + i, res + j, base, comp);
	else if (len % 3 == 1)
		num1(str + i, res + j, base, comp);
	return (res);
}
