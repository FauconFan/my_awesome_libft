/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:15:01 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/05 10:03:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	unsigned int		index;
	char				*res;

	if (s == 0)
		return (0);
	res = ft_strdup((char *)s);
	index = 0;
	while (s[index])
	{
		res[index] = f(s[index]);
		index++;
	}
	res[index] = 0;
	return (res);
}
