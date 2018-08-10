/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_any.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:10:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 15:45:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_str_any(char *s, t_bool (*f)(int c))
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (f(s[index]) != 0)
			return (TRUE);
		index++;
	}
	return (FALSE);
}
