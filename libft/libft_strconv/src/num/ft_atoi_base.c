/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:24:46 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:40:45 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strconv.h"
#include "libft_strstd.h"

static const char	*update_str(const char *str)
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

static int			validate_base(const char *base)
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

static int			get_place_in_base(char c, const char *base)
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

static int			atoi_real(
						const char *str,
						const char *base,
						size_t length_base)
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

int					ft_atoi_base(char const *str, const char *base)
{
	size_t		length_base;
	const char	*cpy;

	length_base = ft_strlen(base);
	cpy = str;
	if (length_base <= 1)
		return (0);
	if (validate_base(base) == 0)
		return (0);
	cpy = update_str(cpy);
	return (atoi_real(cpy, base, length_base));
}
