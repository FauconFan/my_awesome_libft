/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:10:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/12 18:13:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsetnew(int len, char c)
{
	char	*res;
	int		i;

	res = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		res[i] = c;
		i++;
	}
	return (res);
}
