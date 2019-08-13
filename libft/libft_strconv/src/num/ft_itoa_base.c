/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 07:55:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 17:02:31 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strconv.h"
#include "libft_strstd.h"
#include "libft_memory.h"
#include "libft_math.h"

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

char			*ft_itoa_base(int n, const char *base)
{
	char	*res;
	int		index;
	int		len;
	size_t	lenbase;

	lenbase = ft_strlen(base);
	len = my_log(n, (int)lenbase);
	index = 0;
	ft_memcheck((res = malloc((size_t)len + 1)));
	if (n == 0)
		return (returnzero(res));
	else if (n < 0)
		res[0] = '-';
	index = (int)len - 1;
	while (n)
	{
		res[index] = base[(unsigned int)ft_abs(n) % lenbase];
		index--;
		n /= lenbase;
	}
	res[len] = 0;
	return (res);
}
