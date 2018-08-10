/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:09:13 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/27 08:09:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x7F)
		return (1);
	else if (wchar <= 0x7FF)
		return (2);
	else if (wchar <= 0xFFFF)
		return (3);
	else if (wchar <= 0x10FFFF)
		return (4);
	return (0);
}
