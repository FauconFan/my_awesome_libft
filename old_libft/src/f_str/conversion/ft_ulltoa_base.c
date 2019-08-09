/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:07:09 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/24 22:31:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulltoa_base(unsigned long long n, char *base)
{
	char	*res;
	int		index;
	int		len;
	int		baselen;

	if (n == 0)
		return (ft_strdup("0"));
	baselen = ft_strlen(base);
	len = ft_logullb(n, baselen);
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
