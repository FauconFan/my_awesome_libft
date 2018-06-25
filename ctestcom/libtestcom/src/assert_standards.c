/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_standards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:28:32 by fauconfa          #+#    #+#             */
/*   Updated: 2018/06/25 14:56:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

void		assert(short is_passed)
{
	add_test_to_env(init_new_test(ASSERT, is_passed));
}

void		assert_null(void *ptr)
{
	add_test_to_env(init_new_test(ASSERT_NULL, ptr == NULL));
}

void		assert_notnull(void *ptr)
{
	add_test_to_env(init_new_test(ASSERT_NOT_NULL, ptr != NULL));
}
