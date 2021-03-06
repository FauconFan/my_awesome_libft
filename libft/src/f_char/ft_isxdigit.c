/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:57:27 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 15:45:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_isxdigit(int c)
{
	return (ft_isdigit(c) ||
		(c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F') ? TRUE : FALSE);
}
