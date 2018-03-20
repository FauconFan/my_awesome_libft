/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:24:46 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/11 16:39:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*update_str(char *str)
{
	int		index;
	char	c;

	index = 0;
	c = str[index];
	while (c != '\0' && (c == ' ' || c == '\n' || c == '\t'
				|| c == '\r' || c == '\f' || c == '\v'))
	{
		index++;
		c = str[index];
	}
	return (str + index);
}

static int		validate_base(char *base)
{
	int		index[2];

	index[0] = 0;
	while (base[index[0]] != '\0')
	{
		if (base[index[0]] == '+' || base[index[0]] == '-')
			return (0);
		index[1] = index[0] + 1;
		while (base[index[1]] != '\0')
		{
			if (base[index[0]] == base[index[1]])
				return (0);
			index[1]++;
		}
		index[0]++;
	}
	return (1);
}

static int		get_place_in_base(char c, char *base)
{
	int		index;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

static int		atoi_real(char *str, char *base, int length_base)
{
	int		sign;
	int		res;
	int		tmp;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	while (*str && (tmp = get_place_in_base(*str, base)) != -1)
	{
		res *= length_base;
		res -= tmp;
		str++;
	}
	return (res * -sign);
}

int				ft_atoi_base(char *str, char *base)
{
	int		length_base;

	length_base = 0;
	while (base[length_base])
		length_base++;
	if (length_base <= 1)
		return (0);
	if (validate_base(base) == 0)
		return (0);
	str = update_str(str);
	return (atoi_real(str, base, length_base));
}
