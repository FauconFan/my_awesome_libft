/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:07:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/15 23:52:44 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strconv.h"
#include "libft_strstd.h"
#include "libft_math.h"

char		*ft_lltoa_base(long long n, const char *base)
{
	char			*res;
	unsigned int	index;
	unsigned int	len;
	size_t			baselen;

	if (n == 0)
		return (ft_strdup("0"));
	baselen = ft_strlen(base);
	if (n < 0)
		len = 1 + ft_logullb((unsigned long long)-n, baselen);
	else
		len = ft_logullb((unsigned long long)n, baselen);
	if ((res = malloc((size_t)len + 1)) == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	index = len - 1;
	while (n)
	{
		res[index] = base[(unsigned long long)ft_llabs(n) % baselen];
		index--;
		n /= baselen;
	}
	res[len] = 0;
	return (res);
}
