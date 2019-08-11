/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:07:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/11 11:05:08 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strconv.h"
#include "libft_strstd.h"
#include "libft_math.h"

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
