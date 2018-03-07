/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_standards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:28:32 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/14 12:01:03 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

void		assert(short is_passed)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT, is_passed);
	add_test_to_env(test);
}

void		assertNull(void *ptr)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NULL, ptr == NULL);
	add_test_to_env(test);
}

void		assertNotNull(void *ptr)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_NOT_NULL, ptr != NULL);
	add_test_to_env(test);
}
