/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 08:13:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:45:25 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strconv.h"
#include "libft_strstd.h"
#include "libft_memory.h"

static int		place_in_str(char c, const char *s)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
		{
			return (index);
		}
		index++;
	}
	return (-1);
}

static int		build_number_deci(char *nbr, const char *base_from, int length_base)
{
	int		index;
	int		sign;
	int		nb;

	nb = 0;
	index = 0;
	sign = (*nbr == '-') ? 1 : 0;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	while (nbr[index])
	{
		nb *= length_base;
		nb -= place_in_str(nbr[index], base_from);
		index++;
	}
	if (sign == 0)
		nb *= -1;
	return (nb);
}

static int		get_length_number_in_base(int nb, int length_base)
{
	int		length;

	length = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		length++;
		nb = nb / length_base;
	}
	return (length);
}

char			*ft_convert_base(
					char *nbr,
					const char *base_from,
					const char *base_to)
{
	int		length[6];
	char	*res;

	length[0] = (int)ft_strlen(base_from);
	length[1] = (int)ft_strlen(base_to);
	length[4] = 0;
	length[3] = build_number_deci(nbr, base_from, length[0]);
	length[2] = get_length_number_in_base(length[3], length[1]);
	if (*nbr == '-' && *nbr == '+')
		nbr++;
	ft_memcheck((res = malloc((size_t)length[2] + 1)));
	if (*nbr == '-')
	{
		length[2]++;
		length[4] = 1;
		res[0] = '-';
	}
	res[length[2]] = '\0';
	while (--length[2] >= length[4])
	{
		length[5] = length[3] % length[1];
		res[length[2]] = base_to[(length[5] < 0) ? -length[5] : length[5]];
		length[3] = length[3] / length[1];
	}
	return (res);
}
