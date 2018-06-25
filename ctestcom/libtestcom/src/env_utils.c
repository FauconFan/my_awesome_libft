/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:21:55 by fauconfa          #+#    #+#             */
/*   Updated: 2018/06/25 16:06:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

t_testcom 	*g_env_testcom = NULL;

static void		add_test_handle_llist(t_simpletest *test) {
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
}

static void		log_meta_test(t_simpletest *test) {
	g_env_testcom->meta->nb_test++;
	if (test->is_passed)
	{
		g_env_testcom->meta->nb_test_passed++;
	}
	else
	{
		g_env_testcom->meta->nb_test_failed++;
	}
	switch (test->type) {
		case ASSERT:
			g_env_testcom->meta->nb_assert++;
			g_env_testcom->meta->nb_assert_failed += (test->is_passed) ? 0 : 1;
			break;
		case ASSERT_NULL:
			g_env_testcom->meta->nb_assert_null++;
			g_env_testcom->meta->nb_assert_null_failed += (test->is_passed) ? 0 : 1;
			break;
		case ASSERT_NOT_NULL:
			g_env_testcom->meta->nb_assert_not_null++;
			g_env_testcom->meta->nb_assert_not_null_failed += (test->is_passed) ? 0 : 1;
			break;
		case ASSERT_NUM:
			g_env_testcom->meta->nb_assert_num++;
			g_env_testcom->meta->nb_assert_num_failed += (test->is_passed) ? 0 : 1;
			break;
		case ASSERT_STRING:
			g_env_testcom->meta->nb_assert_string++;
			g_env_testcom->meta->nb_assert_string_failed += (test->is_passed) ? 0 : 1;
			break;
		case ASSERT_ARR:
			g_env_testcom->meta->nb_assert_arr++;
			g_env_testcom->meta->nb_assert_arr_failed += (test->is_passed) ? 0 : 1;
			break;

	}
}

void		add_test_to_env(t_simpletest *test)
{
	init_env_testcom();
	add_test_handle_llist(test);
	log_meta_test(test);
}

void		free_n_print_result()
{
	int		nb_test_failed;

	if (g_env_testcom == NULL)
	{
		dprintf(2, "Unexcepted error...\n");
	}
	else if (g_env_testcom->meta->nb_test == 0) {
		printf("Not enough tests is provided...\n");
	}
	else {
		nb_test_failed = g_env_testcom->meta->nb_test_failed;
		printf("All tests %d\n\tTest passed %d\n\tTest failed %d\n",
		g_env_testcom->meta->nb_test,
		g_env_testcom->meta->nb_test_passed,
		g_env_testcom->meta->nb_test_failed);
		printf("\tAssert tests : %d", g_env_testcom->meta->nb_assert);
		if (g_env_testcom->meta->nb_assert_failed) {
			printf(" (Failed %d)\n", g_env_testcom->meta->nb_assert_failed);
		}
		else {
			printf("\n");
		}
		printf("\tAssert Null tests : %d", g_env_testcom->meta->nb_assert_null);
		if (g_env_testcom->meta->nb_assert_null_failed) {
			printf(" (Failed %d)\n", g_env_testcom->meta->nb_assert_null_failed);
		}
		else {
			printf("\n");
		}
		printf("\tAssert Not Null tests : %d", g_env_testcom->meta->nb_assert_not_null);
		if (g_env_testcom->meta->nb_assert_not_null_failed) {
			printf(" (Failed %d)\n", g_env_testcom->meta->nb_assert_not_null_failed);
		}
		else {
			printf("\n");
		}
		printf("\tAssert Num tests : %d", g_env_testcom->meta->nb_assert_num);
		if (g_env_testcom->meta->nb_assert_num_failed) {
			printf(" (Failed %d)\n", g_env_testcom->meta->nb_assert_num_failed);
		}
		else {
			printf("\n");
		}
		printf("\tAssert String tests : %d", g_env_testcom->meta->nb_assert_string);
		if (g_env_testcom->meta->nb_assert_string_failed) {
			printf(" (Failed %d)\n", g_env_testcom->meta->nb_assert_string_failed);
		}
		else {
			printf("\n");
		}
		printf("\tAssert Array tests : %d", g_env_testcom->meta->nb_assert_arr);
		if (g_env_testcom->meta->nb_assert_arr_failed) {
			printf(" (Failed %d)\n", g_env_testcom->meta->nb_assert_arr_failed);
		}
		else {
			printf("\n");
		}
		free_env_testcom();
		if (nb_test_failed)
			exit(1);
	}
}
