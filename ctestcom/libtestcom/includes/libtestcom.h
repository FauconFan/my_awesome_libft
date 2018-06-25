/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtestcom.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:02:41 by fauconfa          #+#    #+#             */
/*   Updated: 2018/06/25 15:49:37 by jpriou           ###   ########.fr       */
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

/*
**	Handle compareason with bit values
*/

# define EQU			0b00100
# define GT				0b01000
# define LT				0b10000
# define GTE			0b01100
# define LTE			0b10100

typedef enum		e_typetest
{
	ASSERT,
	ASSERT_NULL,
	ASSERT_NOT_NULL,
	ASSERT_NUM,
	ASSERT_STRING,
	ASSERT_ARR
}					t_typetest;

typedef struct		s_simpletest
{
	t_typetest						type;
	short							is_passed;
	struct s_simpletest				*next;
	struct s_simpletest				*prev;
}					t_simpletest;

typedef struct		s_meta_stats_tests
{
	int					nb_test;
	int					nb_test_passed;
	int					nb_test_failed;
	int					nb_assert;
	int					nb_assert_failed;
	int					nb_assert_null;
	int					nb_assert_null_failed;
	int					nb_assert_not_null;
	int					nb_assert_not_null_failed;
	int					nb_assert_num;
	int					nb_assert_num_failed;
	int					nb_assert_string;
	int					nb_assert_string_failed;
	int					nb_assert_arr;
	int					nb_assert_arr_failed;
}					t_meta_stats_tests;

typedef struct		s_testcom
{
	t_meta_stats_tests	*meta;
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
void				assert_null(void *ptr);
void				assert_notnull(void *ptr);

void				assert_char(char a, char b, int comp);
void				assert_short(short a, short b, int comp);
void				assert_int(int a, int b, int comp);
void				assert_long(long a, long b, int comp);
void				assert_long_long(long long a, long long b, int comp);
void				assert_float(float a, float b, int comp);
void				assert_double(double a, double b, int comp);
void				assert_long_double(long double a, long double b, int comp);
void				assert_unsigned_char(unsigned char a, unsigned char b, int comp);
void				assert_unsigned_short(unsigned short a, unsigned short b, int comp);
void				assert_unsigned_int(unsigned int a, unsigned int b, int comp);
void				assert_unsigned_long(unsigned long a, unsigned long b, int comp);
void				assert_unsigned_long_long(unsigned long long a, unsigned long long b, int comp);

void				assert_strequ(char *s1, char *s2);
void				assert_strlen(char *s, unsigned int len);
void				assert_strlengteq(char *s, unsigned int len);
void				assert_strlengt(char *s, unsigned int len);
void				assert_strlenlteq(char *s, unsigned int len);
void				assert_strlenlt(char *s, unsigned int len);

void				assert_str_match(char *s, char *pattern);
void				assert_str_beginwith(char *big, char *little);
void				assert_str_endwith(char *big, char *little);
void				assert_str_contains(char *big, char *little);
void				assert_str_countchar(char *str, char c, size_t nb);
void				assert_str_countlines(char *str, size_t nb);

void				assert_str_isprintable(char *str);
void				assert_str_isascii(char *str);
void				assert_str_isalnum(char *str);

void				assert_arr_char(char a[], char b[], size_t len);
void				assert_arr_short(short a[], short b[], size_t len);
void				assert_arr_int(int a[], int b[], size_t len);
void				assert_arr_long(long a[], long b[], size_t len);
void				assert_arr_long_long(long long a[], long long b[], size_t len);
void				assert_arr_float(float a[], float b[], size_t len);
void				assert_arr_double(double a[], double b[], size_t len);
void				assert_arr_long_double(long double a[], long double b[], size_t len);
void				assert_arr_unsigned_char(unsigned char a[], unsigned char b[], size_t len);
void				assert_arr_unsigned_short(unsigned short a[], unsigned short b[], size_t len);
void				assert_arr_unsigned_int(unsigned int a[], unsigned int b[], size_t len);
void				assert_arr_unsigned_long(unsigned long a[], unsigned long b[], size_t len);
void				assert_arr_unsigned_long_long(unsigned long long a[], unsigned long long b[], size_t len);

void 				assert_arr_str(char **s1, char **s2, size_t len);
#endif
