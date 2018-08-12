/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 07:55:17 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/12 16:32:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		my_log(int n, int len)
{
	if (n < 0)
		return (1 + ft_logib(-n, len));
	return (ft_logib(n, len));
}

static char		*returnzero(char *res)
{
	res[0] = '0';
	res[1] = 0;
	return (res);
}

char			*ft_itoa_base(int n, char *base)
{
	char	*res;
	int		index;
	int		len;
	int		lenbase;

	lenbase = ft_strlen(base);
	len = my_log(n, lenbase);
	index = 0;
	ft_memcheck((res = (char *)malloc(sizeof(char) * (len + 1))));
	if (n == 0)
		return (returnzero(res));
	else if (n < 0)
		res[0] = '-';
	index = (int)len - 1;
	while (n)
	{
		res[index] = base[(n % lenbase) * ((n < 0) ? -1 : 1)];
		index--;
		n /= lenbase;
	}
	res[len] = 0;
	return (res);
}
