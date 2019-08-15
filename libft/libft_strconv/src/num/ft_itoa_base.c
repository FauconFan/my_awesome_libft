/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 07:55:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/15 23:50:55 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strconv.h"
#include "libft_strstd.h"
#include "libft_memory.h"
#include "libft_math.h"

static unsigned int		my_log(int n, size_t len)
{
	if (n < 0)
		return (1 + ft_loguib((unsigned int)-n, len));
	return (ft_loguib((unsigned int)n, len));
}

static char		*returnzero(char *res)
{
	res[0] = '0';
	res[1] = 0;
	return (res);
}

char			*ft_itoa_base(int n, const char *base)
{
	char			*res;
	int				index;
	unsigned int	len;
	size_t			lenbase;

	lenbase = ft_strlen(base);
	len = my_log(n, lenbase);
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
