/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:08:52 by fauconfan         #+#    #+#             */
/*   Updated: 2018/03/20 18:26:39 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtestcom.h"

static int	ct_match(char *str, char *pattern)
{
	if (*str != 0 && *pattern == '*')
		return (ct_match(str + 1, pattern) || ct_match(str, pattern + 1));
	else if (*str == 0 && *pattern == '*')
		return (ct_match(str, pattern + 1));
	else if (*str == *pattern && *str != 0 && *pattern != 0)
		return (ct_match(str + 1, pattern + 1));
	else if (*str == *pattern && *str == 0 && *pattern == 0)
		return (1);
	return (0);
}

void		assert_strequ(char *s1, char *s2)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_STRING, strcmp(s1, s2) == 0);
	add_test_to_env(test);
}

void		assert_strlen(char *s, unsigned int len)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_STRING, strlen(s) == len);
	add_test_to_env(test);
}

void		assert_strlengteq(char *s, unsigned int len)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_STRING, strlen(s) >= len);
	add_test_to_env(test);
}

void		assert_strlengt(char *s, unsigned int len)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_STRING, strlen(s) > len);
	add_test_to_env(test);
}

void		assert_strlenlteq(char *s, unsigned int len)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_STRING, strlen(s) <= len);
	add_test_to_env(test);
}

void		assert_strlenlt(char *s, unsigned int len)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_STRING, strlen(s) < len);
	add_test_to_env(test);
}

void		assert_str_match(char *s, char *pattern)
{
	t_simpletest	*test;

	test = init_new_test(ASSERT_STRING, ct_match(s, pattern));
	add_test_to_env(test);
}

void		assert_str_beginwith(char *big, char *little)
{
	t_simpletest	*test;
	char			*pattern;
	size_t			len;

	len = strlen(little);
	if ((pattern = (char *)malloc(sizeof(char) * (len + 2))) == 0)
		exit(1);
	strcpy(pattern, little);
	pattern[len] = '*';
	pattern[len + 1] = 0;
	test = init_new_test(ASSERT_STRING, ct_match(big, pattern));
	add_test_to_env(test);
	free(pattern);
}

void		assert_str_endwith(char *big, char *little)
{
	t_simpletest	*test;
	char			*pattern;
	size_t			len;

	len = strlen(little);
	if ((pattern = (char *)malloc(sizeof(char) * (len + 2))) == 0)
		exit(1);
	pattern[0] = '*';
	strcpy(pattern + 1, little);
	pattern[len + 1] = 0;
	test = init_new_test(ASSERT_STRING, ct_match(big, pattern));
	add_test_to_env(test);
	free(pattern);
}

void		assert_str_contains(char *big, char *little)
{
	t_simpletest	*test;
	char			*pattern;
	size_t			len;

	len = strlen(little);
	if ((pattern = (char *)malloc(sizeof(char) * (len + 3))) == 0)
		exit(1);
	pattern[0] = '*';
	strcpy(pattern + 1, little);
	pattern[len + 1] = '*';
	pattern[len + 2] = 0;
	test = init_new_test(ASSERT_STRING, ct_match(big, pattern));
	add_test_to_env(test);
	free(pattern);
}

void		assert_str_countlines(char *str, size_t nb)
{
	assert_str_countchar(str, '\n', nb);
}

void		assert_str_countchar(char *str, char c, size_t nb)
{
	t_simpletest	*test;
	short			is_passed;

	is_passed = 42;
	while (*str)
	{
		if (*str == c)
		{
			if (nb == 0)
			{
				is_passed = 0;
				break ;
			}
			--nb;
		}
		str++;
	}
	if (is_passed != 0 && nb != 0)
		is_passed = 0;
	test = init_new_test(ASSERT_STRING, is_passed);
	add_test_to_env(test);
}

void		assert_str_isprintable(char *str)
{
	t_simpletest	*test;
	short			is_passed;

	is_passed = 42;
	while (*str)
	{
		if ((*str >= 32 && *str < 127) == 0)
		{
			is_passed = 0;
			break ;
		}
		str++;
	}
	test = init_new_test(ASSERT_STRING, is_passed);
	add_test_to_env(test);
}

void		assert_str_isascii(char *str)
{
	t_simpletest	*test;
	short			is_passed;

	is_passed = 42;
	while (*str)
	{
		if ((*str >= 0 && *str < 127) == 0)
		{
			is_passed = 0;
			break ;
		}
		str++;
	}
	test = init_new_test(ASSERT_STRING, is_passed);
	add_test_to_env(test);
}

void		assert_str_isalnum(char *str)
{
	t_simpletest	*test;
	short			is_passed;

	is_passed = 42;
	while (*str)
	{
		if (((*str >= 'a' && *str <= 'z')
			|| (*str >= 'A' && *str <= 'Z')
			|| (*str >= '0' && *str <= '9')) == 0)
		{
			is_passed = 0;
			break ;
		}
		str++;
	}
	test = init_new_test(ASSERT_STRING, is_passed);
	add_test_to_env(test);
}
