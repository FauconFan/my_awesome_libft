/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbase64_process_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:41:51 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 13:56:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		get_rep6bits(char c, char base[64])
{
	int		res;

	res = 0;
	while (res < 64)
	{
		if (base[res] == c)
			return (res);
		res++;
	}
	return (-1);
}

void			dnum2(char *str, uint8_t *res, char base[64])
{
	char	d[2];

	d[0] = get_rep6bits(str[0], base);
	d[1] = get_rep6bits(str[1], base);
	res[0] = (d[0] << 2) | (d[1] >> 4);
}

void			dnum3(char *str, uint8_t *res, char base[64])
{
	char	d[4];

	d[0] = get_rep6bits(str[0], base);
	d[1] = get_rep6bits(str[1], base);
	d[2] = get_rep6bits(str[2], base);
	res[0] = (d[0] << 2) | (d[1] >> 4);
	res[1] = (d[1] << 4) | (d[2] >> 2);
}

void			dnum4(char *str, uint8_t *res, char base[64])
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
