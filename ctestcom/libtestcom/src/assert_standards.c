/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_standards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:28:32 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/20 09:49:47 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

void		assert(short is_passed)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT, is_passed);
	add_test_to_env(test);
}

void		assert_null(void *ptr)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NULL, ptr == NULL);
	add_test_to_env(test);
}

void		assert_notnull(void *ptr)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NOT_NULL, ptr != NULL);
	add_test_to_env(test);
}
