/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:09:13 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/16 00:09:38 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_wchar.h"

/*
**	man utf-8
*/

int		ft_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x0000007F)
		return (1);
	else if (wchar <= 0x000007FF)
		return (2);
	else if (wchar <= 0x0000FFFF)
		return (3);
	else if (wchar <= 0x001FFFFF)
		return (4);
	else if (wchar <= 0x03FFFFFF)
		return (5);
	return (6);
}
