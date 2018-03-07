/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:21:55 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/07 14:01:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

t_testcom 	*g_env_testcom = NULL;

void		add_test_to_env(t_simpletest *test)
{
	init_env_testcom();
	if (g_env_testcom->first == NULL)
	{
		g_env_testcom->first = test;
		g_env_testcom->last = test;
	}
	else
	{
		g_env_testcom->last->next = test;
		test->prev = g_env_testcom->last;
		g_env_testcom->last = test;
	}
	if (test->is_passed)
	{
		g_env_testcom->nb_test_passed++;
	}
	else
	{
		g_env_testcom->nb_test_failed++;
	}
	g_env_testcom->nb_test++;
}

void		free_n_print_result()
{
	int		nb_test_failed;

	if (g_env_testcom == NULL)
	{
		dprintf(2, "You don't have specified any tests...\n");
		exit(1);
	}
	nb_test_failed = g_env_testcom->nb_test_failed;
	printf("All tests %d\n\tTest passed %d\n\tTest failed %d\n",
		g_env_testcom->nb_test,
		g_env_testcom->nb_test_passed,
		g_env_testcom->nb_test_failed);
	free_env_testcom();
	if (nb_test_failed)
		exit(1);
}
