/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:10:52 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 16:30:54 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strstd.h"

char		*ft_strsetnew(size_t len, char c)
{
	char	*res;
	size_t	i;

	res = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		res[i] = c;
		i++;
	}
	return (res);
}
