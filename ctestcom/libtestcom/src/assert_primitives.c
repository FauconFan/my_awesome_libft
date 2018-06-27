/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_primitives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 10:00:25 by fauconfa          #+#    #+#             */
/*   Updated: 2018/06/27 09:37:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

# define TEST_EQUALS 	0b00100
# define TEST_GREATER	0b01000
# define TEST_LESS		0b10000

# define TREAT_H__(h)	(h == -1 ? TEST_LESS : h)
# define TREAT_H_(h)	(h == 1 ? TEST_GREATER : TREAT_H__(h))
# define TREAT_H(h)		(h == 0 ? TEST_EQUALS : TREAT_H_(h))

# define TEST__E(a,b,h) ((h & TEST_EQUALS) ? a == b : 0)
# define TEST__G(a,b,h) ((h & TEST_GREATER) ? a > b : 0)
# define TEST__L(a,b,h) ((h & TEST_LESS) ? a < b : 0)
# define TEST_(a,b,h) 	(TEST__E(a,b,h) || TEST__L(a,b,h) || TEST__G(a,b,h))

# define TEST(a,b,h) 	(TEST_(a,b,TREAT_H(h)))

# define FUNC_CON()				add_test_to_env(init_new_test(ASSERT_NUM, \
									TEST(a, b, comp)));
# define FUNC_PROTO(type)		type a, type b, int comp

void	assert_char(FUNC_PROTO(char)){ FUNC_CON() }
void	assert_short(FUNC_PROTO(short)){ FUNC_CON() }
void	assert_int(FUNC_PROTO(int)){ FUNC_CON() }
void	assert_long(FUNC_PROTO(long)){ FUNC_CON() }
void	assert_long_long(FUNC_PROTO(long long)){ FUNC_CON() }
void	assert_float(FUNC_PROTO(float)){ FUNC_CON() }
void	assert_double(FUNC_PROTO(double)){ FUNC_CON() }
void	assert_long_double(FUNC_PROTO(long double)){ FUNC_CON() }
void	assert_unsigned_char(FUNC_PROTO(unsigned char)){ FUNC_CON() }
void	assert_unsigned_short(FUNC_PROTO(unsigned short)){ FUNC_CON() }
void	assert_unsigned_int(FUNC_PROTO(unsigned int)){ FUNC_CON() }
void	assert_unsigned_long(FUNC_PROTO(unsigned long)){ FUNC_CON() }
void	assert_unsigned_long_long(FUNC_PROTO(unsigned long long)){ FUNC_CON() }
