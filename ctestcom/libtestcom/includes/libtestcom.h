/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtestcom.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:02:41 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/20 17:46:36 by fauconfan        ###   ########.fr       */
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

# define TEST_EQUALS 	0b00100
# define TEST_GREATER	0b01000
# define TEST_LESS		0b10000

# define TREAT_H__(h)	(h == -1 ? TEST_LESS : h)
# define TREAT_H_(h)	(h == 1 ? TEST_GREATER : TREAT_H__(h))
# define TREAT_H(h)		(h == 0 ? TEST_EQUALS : TREAT_H_(h))

# define TEST__E(a,b,h) ((h & TEST_EQUALS) ? a == b : 0)
# define TEST__G(a,b,h) ((h & TEST_GREATER) ? a > b : 0)
# define TEST__L(a,b,h) ((h & TEST_LESS) ? a < b : 0)
# define TEST_(a,b,h) 	(TEST__E(a,b,h) || TEST__L(a,b,h) || TEST__G(a,b,h))

# define TEST(a,b,h) 	(TEST_(a,b,TREAT_H(h)))

typedef enum		e_typetest
{
	ASSERT,
	ASSERT_NULL,
	ASSERT_NOT_NULL,
	ASSERT_NUM_EQUALS,
	ASSERT_STRING
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

#endif
