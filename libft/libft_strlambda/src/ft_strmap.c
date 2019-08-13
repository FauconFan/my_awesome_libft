/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 22:15:01 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 18:20:19 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strlambda.h"
#include "libft_strstd.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	unsigned int		index;
	char				*res;

	if (s == 0)
		return (0);
	res = ft_strdup(s);
	index = 0;
	while (s[index])
	{
		res[index] = f(s[index]);
		index++;
	}
	res[index] = 0;
	return (res);
}
