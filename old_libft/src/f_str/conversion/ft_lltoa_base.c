/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:07:09 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/24 22:31:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	len = (n < 0) ? 1 + ft_logllb(-n, baselen) : ft_logllb(n, baselen);
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
