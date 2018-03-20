/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_primitives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 10:00:25 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/20 11:11:59 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

void		assert_char(char a, char b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_short(short a, short b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_int(int a, int b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_long(long a, long b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_long_long(long long a, long long b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_float(float a, float b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_double(double a, double b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_long_double(long double a, long double b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}


void		assert_unsigned_char(unsigned char a, unsigned char b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_unsigned_short(unsigned short a, unsigned short b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_unsigned_int(unsigned int a, unsigned int b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_unsigned_long(unsigned long a, unsigned long b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}

void		assert_unsigned_long_long(unsigned long long a, unsigned long long b, int comp)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NUM_EQUALS, TEST(a, b, comp));
	add_test_to_env(test);
}
