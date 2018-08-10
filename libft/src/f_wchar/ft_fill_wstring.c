/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:10:33 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/27 08:45:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill_wstring_len(wchar_t wchar, char *str, int size)
{
	if (size == 1)
		str[0] = wchar;
	else if (size == 2)
	{
		str[0] = ((wchar >> 6) + 0xc0);
		str[1] = ((wchar & 0x3F) + 0x80);
	}
	else if (size == 3)
	{
		str[0] = (((wchar >> 12) & 0xF) + 0xE0);
		str[1] = (((wchar >> 6) & 0x3F) + 0x80);
		str[2] = ((wchar & 0x3F) + 0x80);
	}
	else
	{
		str[0] = (((wchar >> 18) & 0x7) + 0xF0);
		str[1] = (((wchar >> 12) & 0x3F) + 0x80);
		str[2] = (((wchar >> 6) & 0x3F) + 0x80);
		str[3] = ((wchar & 0x3F) + 0x80);
	}
}

void    ft_fill_wstring(wchar_t wchar, char *str)
{
    ft_fill_wstring_len(wchar, str, ft_wcharlen(wchar));
}
