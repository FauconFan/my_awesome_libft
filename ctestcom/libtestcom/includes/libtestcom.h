/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtestcom.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:02:41 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/14 11:56:53 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTESTCOM_H
# define LIBTESTCOM_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# ifndef TRUE
# define TRUE		1
# endif

# ifndef FALSE
# define FALSE		0
# endif

typedef enum		e_typetest
{
	ASSERT,
	ASSERT_NULL,
	ASSERT_NOT_NULL,
	ASSERT_NUM_EQUALS,
	ASSERT_DOUBLE_EQUALS,
	ASSERT_STR_EQUALS,
	ASSERT_ARR_NUM_EQUALS,
	ASSERT_ARR_DOUBLE_EQUALS,
	ASSERT_ARR_STR_EQUALS
}					t_typetest;

typedef struct		s_simpletest
{
	t_typetest						type;
	short							is_passed;
	struct s_simpletest				*next;
	struct s_simpletest				*prev;
}					t_simpletest;

typedef struct		s_testcom
{
	int					nb_test;
	int					nb_test_passed;
	int					nb_test_failed;
	t_simpletest		*first;
	t_simpletest		*last;
}					t_testcom;

extern t_testcom			*g_env_testcom;

/*
**	Malloc utils
*/

void				init_env_testcom();
t_simpletest		*init_new_test(t_typetest type, short is_passed);
void				free_env_testcom();
void				free_all_tests(t_simpletest *test);

/*
**	Env utils
*/

void				add_test_to_env(t_simpletest *test);
void				free_n_print_result();

/*
**	Assert utils
*/

void				assert(short is_passed);
void				assertNull(void *ptr);
void				assertNotNull(void *ptr);

#endif