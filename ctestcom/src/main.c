/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:20:17 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/20 18:26:01 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ctestcom.h"

void	ft_printusage(void)
{
	dprintf(2, "./ctestcom PATH_ORIGIN PATH_TARGET\n");
}

int		main(int argc, char **argv)
{
	t_ctestcom	*ctestcom;

	if (argc != 3)
	{
		ft_printusage();
		exit (1);
	}
	ctestcom = init_ctestcom(argv[1], argv[2]);
	tct_parser(ctestcom);
	tct_addcontext(ctestcom);
	dprintf(ctestcom->fd_target, "%s", ctestcom->generate_string);
	free_ctestcom(&ctestcom);
	return (0);
}

/*
** Testcom :
**	printf("main test\n");
**	assert(1);
**	assert(1);
**	assert_null(0);
**	assert_notnull(&strlen);
**	
**	assert_char('c', 'c', 0);
**	assert_short((short)-2, (short)-2, 0);
**	assert_int(42, 42, 0);
**	assert_long((long) -123456789123456789, (long) -123456789123456789, 0);
**	assert_long_long((long long) 123456789123456789, (long long) 123456789123456789, 0);
**	assert_float(-0.5f, -0.5f, 0);
**	assert_double(-0.5, -0.5, 0);
**	assert_long_double(((long double)5.0)/3.0, ((long double)5.0)/3.0, 0);
**	assert_unsigned_char('c', 'c', 0);
**	assert_unsigned_short((short)2, (short)2, 0);
**	assert_unsigned_int(42, 42, 0);
**	assert_unsigned_long((long) 123456789123456789, (long) 123456789123456789, 0);
**	assert_unsigned_long_long((long long) 123456789123456789, (long long) 123456789123456789, 0);
**	assert_char('d', 'c', 1);
**	assert_char('c', 'c', EQU);
**	assert_char('d', 'c', GTE);
**	assert_char('d', 'c', GT);
**	assert_char('b', 'c', LTE);
**	assert_char('b', 'c', LT);
**	assert_char('c', 'c', LTE);
**	assert_char('c', 'c', GTE);
**	assert_short((short)-2, (short)-2, GTE);
**	assert_short((short)-2, (short)-2, LTE);
**	assert_int(42, 42, 0);
**	assert_int(42, 41, 1);
**	assert_int(42, 43, -1);
**	assert_int(42, 42, GTE);
**	assert_int(42, 42, LTE);
**	assert_int(43, 42, GT);
**	assert_int(42, 43, LT);
**
**	assert_strequ("Coucou", "Coucou");
**	assert_str_beginwith("Coucou", "Cou");
**	assert_str_endwith("Coucou", "cou");
**	assert_str_contains("Coucou", "cou");
**	assert_str_contains("Coucou", "ouc");
**	assert_str_contains("Coucou", "Coucou");
**	assert_str_contains("Coucou", "ouco");
**	
**	assert_str_countlines("coucoucououcocuoucocuo\n", 1);
**	assert_str_countchar("coucoucoucoucoucoucoucoucoucoucoucou\n", 'c', 12);
**	assert_str_countchar("coucoucoucoucoucoucoucoucoucoucoucou\n", 'o', 12);
**	assert_str_countchar("coucoucoucoucoucoucoucoucoucoucoucou\n", 'u', 12);
**	assert_str_isprintable("coucoucoucoucoucoucoucoucoucoucoucou");
**	assert_str_isascii("coucoucoucoucoucoucoucoucoucoucoucou");
**	assert_str_isalnum("coucou123456789");
*/
