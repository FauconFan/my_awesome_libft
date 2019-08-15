/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:10:33 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/16 00:16:05 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_wchar.h"

void	ft_fill_wstring_len(wchar_t wchar, char *str, int size)
{
	if (size == 1)
		str[0] = (char)wchar;
	else if (size == 2)
	{
		str[0] = (char)((wchar >> 6) + 0xC0);
		str[1] = (char)((wchar & 0x3F) + 0x80);
	}
	else if (size == 3)
	{
		str[0] = (char)(((wchar >> 12) & 0xF) + 0xE0);
		str[1] = (char)(((wchar >> 6) & 0x3F) + 0x80);
		str[2] = (char)((wchar & 0x3F) + 0x80);
	}
	else if (size == 4)
	{
		str[0] = (char)(((wchar >> 18) & 0x7) + 0xF0);
		str[1] = (char)(((wchar >> 12) & 0x3F) + 0x80);
		str[2] = (char)(((wchar >> 6) & 0x3F) + 0x80);
		str[3] = (char)((wchar & 0x3F) + 0x80);
	}
	else if (size == 5)
	{
		str[0] = (char)(((wchar >> 24) & 0x3) + 0xF8);
		str[1] = (char)(((wchar >> 18) & 0x3F) + 0x80);
		str[2] = (char)(((wchar >> 12) & 0x3F) + 0x80);
		str[3] = (char)(((wchar >> 6) & 0x3F) + 0x80);
		str[4] = (char)((wchar & 0x3F) + 0x80);
	}
	else
	{
		str[0] = (char)(((wchar >> 30) & 0x1) + 0xFC);
		str[1] = (char)(((wchar >> 24) & 0x3F) + 0x80);
		str[2] = (char)(((wchar >> 18) & 0x3F) + 0x80);
		str[3] = (char)(((wchar >> 12) & 0x3F) + 0x80);
		str[4] = (char)(((wchar >> 6) & 0x3F) + 0x80);
		str[5] = (char)((wchar & 0x3F) + 0x80);
	}
	str[size] = 0;
}

void	ft_fill_wstring(wchar_t wchar, char *str)
{
	ft_fill_wstring_len(wchar, str, ft_wcharlen(wchar));
}
