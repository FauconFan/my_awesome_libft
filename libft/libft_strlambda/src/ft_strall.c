/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:14:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/13 18:19:22 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_strlambda.h"

t_bool		ft_strall(const char *s, t_bool (*f)(int c))
{
	size_t		index;

	index = 0;
	while (s[index])
	{
		if (f(s[index]) == 0)
			return (FALSE);
		index++;
	}
	return (TRUE);
}
