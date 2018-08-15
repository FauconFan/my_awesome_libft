/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_contains_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:02:05 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/15 20:03:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_str_contains_c(char *str, char c)
{
	if (c == '\0')
		return FALSE;
	while (*str)
	{
		if (*str == c)
			return TRUE;
		str++;
	}
	return FALSE;
}
