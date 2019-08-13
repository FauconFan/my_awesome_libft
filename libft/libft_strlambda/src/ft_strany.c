/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strany.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:10:55 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 18:19:18 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strlambda.h"

t_bool		ft_strany(const char *s, t_bool (*f)(int c))
{
	size_t		index;

	index = 0;
	while (s[index])
	{
		if (f(s[index]) != 0)
			return (TRUE);
		index++;
	}
	return (FALSE);
}
