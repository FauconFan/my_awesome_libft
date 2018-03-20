/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_n_ulltoa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:07:09 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/27 12:33:17 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_lltoa_n_ulltoa.h"

static int	my_logll(unsigned long long n, int len)
{
	if (n == 0)
		return (0);
	return (1 + my_logll(n / len, len));
}

char		*ft_lltoa_base(long long n, char *base)
{
	char	*res;
	int		index;
	int		len;
	int		baselen;
	int		b;

	if (n == 0)
		return (ft_strdup("0"));
	baselen = ft_strlen(base);
	len = (n < 0) ? 1 + my_logll(-n, baselen) : my_logll(n, baselen);
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	index = len - 1;
	b = ((n < 0) ? -1 : 1);
	while (n)
	{
		res[index] = base[(n % baselen) * b];
		index--;
		n /= baselen;
	}
	res[len] = 0;
	return (res);
}

char		*ft_ulltoa_base(unsigned long long n, char *base)
{
	char	*res;
	int		index;
	int		len;
	int		baselen;

	if (n == 0)
		return (ft_strdup("0"));
	baselen = ft_strlen(base);
	len = my_logll(n, baselen);
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	index = len - 1;
	while (n)
	{
		res[index] = base[(n % baselen)];
		index--;
		n /= baselen;
	}
	res[len] = 0;
	return (res);
}
