/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:14:17 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 15:45:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_str_all(char *s, t_bool (*f)(int c))
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (f(s[index]) == 0)
			return (FALSE);
		index++;
	}
	return (TRUE);
}
