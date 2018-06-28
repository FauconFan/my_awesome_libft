/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:06:58 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/28 16:02:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Testcom :
**	assert(ft_isalnum('O') == 1);
**	assert(ft_isalnum('L') == 1);
**	assert_short(ft_isalnum('0'), 0, NEQU);
**	assert_short(ft_isalnum('1'), 0, NEQU);
**	assert_short(ft_isalnum('2'), 0, NEQU);
**	assert_short(ft_isalnum('3'), 0, NEQU);
**	assert_short(ft_isalnum('4'), 0, NEQU);
**	assert_short(ft_isalnum('5'), 0, NEQU);
**	assert_short(ft_isalnum('6'), 0, NEQU);
**	assert_short(ft_isalnum('7'), 0, NEQU);
**	assert_short(ft_isalnum('8'), 0, NEQU);
**	assert_short(ft_isalnum('9'), 0, NEQU);
**
**	for (int c = 'a'; c <= 'z'; c++) {
**		assert_short(ft_isalnum(c), 0, NEQU);
**	}
**
**	for (int c = 'A'; c <= 'Z'; c++) {
**		assert_short(ft_isalnum(c), 0, NEQU);
**	}
**
**	assert_short(ft_isalnum(':'), 0, EQU);
**	assert_short(ft_isalnum(';'), 0, EQU);
**	assert_short(ft_isalnum('/'), 0, EQU);
**	assert_short(ft_isalnum('!'), 0, EQU);
**	assert_short(ft_isalnum('!'), 0, EQU);
**	assert_short(ft_isalnum(','), 0, EQU);
**	assert_short(ft_isalnum('.'), 0, EQU);
**	assert_short(ft_isalnum('?'), 0, EQU);
**	assert_short(ft_isalnum('&'), 0, EQU);
**	assert_short(ft_isalnum('\"'), 0, EQU);
**	assert_short(ft_isalnum('\''), 0, EQU);
**	assert_short(ft_isalnum('('), 0, EQU);
**	assert_short(ft_isalnum('-'), 0, EQU);
**	assert_short(ft_isalnum('_'), 0, EQU);
**	assert_short(ft_isalnum('@'), 0, EQU);
**
*/
t_bool		ft_isalnum(int c)
{
	return (((c >= '0' && c <= '9') ||
		(c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z')) ? TRUE : FALSE);
}
