/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:03:32 by fauconfa          #+#    #+#             */
/*   Updated: 2018/06/25 15:49:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

void				init_env_testcom()
{
	if (g_env_testcom != NULL)
		return ;
	if ((g_env_testcom = (t_testcom *)malloc(sizeof(t_testcom))) == 0)
		exit(1);
	if ((g_env_testcom->meta =
			(t_meta_stats_tests *)malloc(sizeof(t_meta_stats_tests))) == 0)
		exit(1);
	g_env_testcom->meta->nb_test = 0;
	g_env_testcom->meta->nb_test_failed = 0;
	g_env_testcom->meta->nb_test_passed = 0;
	g_env_testcom->meta->nb_assert = 0;
	g_env_testcom->meta->nb_assert_failed = 0;
	g_env_testcom->meta->nb_assert_null = 0;
	g_env_testcom->meta->nb_assert_null_failed = 0;
	g_env_testcom->meta->nb_assert_not_null = 0;
	g_env_testcom->meta->nb_assert_not_null_failed = 0;
	g_env_testcom->meta->nb_assert_num = 0;
	g_env_testcom->meta->nb_assert_num_failed = 0;
	g_env_testcom->meta->nb_assert_string = 0;
	g_env_testcom->meta->nb_assert_string_failed = 0;
	g_env_testcom->meta->nb_assert_arr = 0;
	g_env_testcom->meta->nb_assert_arr_failed = 0;
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
		free(g_env_testcom->meta);
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
