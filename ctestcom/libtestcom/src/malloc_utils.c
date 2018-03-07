/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:03:32 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/14 12:01:58 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

void				init_env_testcom()
{
	if (g_env_testcom != NULL)
		return ;
	if ((g_env_testcom = (t_testcom *)malloc(sizeof(t_testcom))) == 0)
		exit(1);
	g_env_testcom->nb_test = 0;
	g_env_testcom->nb_test_failed = 0;
	g_env_testcom->nb_test_passed = 0;
	g_env_testcom->first = NULL;
	g_env_testcom->last = NULL;
}

t_simpletest		*init_new_test(t_typetest type, short is_passed)
{
	t_simpletest	*res;

	if ((res = (t_simpletest *)malloc(sizeof(t_simpletest))) == 0)
		exit(1);
	res->type = type;
	res->is_passed = is_passed;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

void				free_env_testcom()
{
	if (g_env_testcom != NULL)
	{
		free_all_tests(g_env_testcom->first);
		free(g_env_testcom);
		g_env_testcom = NULL;
	}
}

void				free_all_tests(t_simpletest *test)
{
	if (test != NULL)
	{
		free_all_tests(test->next);
		free(test);
	}
}
