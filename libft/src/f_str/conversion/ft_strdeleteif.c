/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeleteif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:43:44 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 16:48:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdeleteif(char *str, t_bool (*f)(int c))
{
	char	*res;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (f(str[i]) == FALSE)
			j++;
	}
	res = ft_strnew(j);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (f(str[i]) == FALSE)
		{
			res[j] = str[i];
			j++;
		}
	}
	return (res);
}
