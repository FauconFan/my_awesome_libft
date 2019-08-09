/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:46:24 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/09 23:39:11 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"

char		ft_toxdigit(char c)
{
	if (ft_isxdigit(c) == FALSE)
		return (-1);
	if (ft_isdigit(c))
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	return (10 + c - 'A');
}
