/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:35:37 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 11:55:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		my_log(int n)
{
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		return (1 + ft_log10(-n));
	return (ft_log10(n));
}

char			*ft_itoa(int n)
{
	char	*res;
	int		index;
	int		len;

	len = my_log(n);
	index = 0;
	ft_memcheck((res = (char *)malloc(sizeof(char) * (len + 1))));
	if (n == 0)
	{
		res[0] = '0';
		res[1] = 0;
		return (res);
	}
	else if (n < 0)
		res[0] = '-';
	index = (int)len - 1;
	while (n)
	{
		res[index] = (n % 10) * ((n < 0) ? -1 : 1) + '0';
		index--;
		n /= 10;
	}
	res[len] = 0;
	return (res);
}
