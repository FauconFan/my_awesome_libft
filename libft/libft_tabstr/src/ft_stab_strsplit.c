/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stab_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:24:48 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 11:10:34 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tabstr.h"
#include "libft_memory.h"

static const char		*ignorechr(const char *s, char c)
{
	while (*s != 0 && *s == c)
		s++;
	return (s);
}

static const char		*ignoreword(const char *s, char c)
{
	while (*s != 0 && *s != c)
		s++;
	return (s);
}

static size_t			len_words(const char *s, char c, size_t *num)
{
	size_t		res;

	*num = 0;
	res = 0;
	s = ignorechr(s, c);
	while (*s)
	{
		s = ignoreword(s, c);
		s = ignorechr(s, c);
		res++;
	}
	return (res);
}

static size_t			len_word(const char *s, char c, size_t *num)
{
	size_t		length;

	*num = 0;
	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

char					**ft_stab_strsplit(char const *s, char c)
{
	size_t		length_tot;
	size_t		length_word;
	size_t		index[2];
	const char	*tmp;
	char		**res;

	if (s == 0)
		return (0);
	length_tot = len_words(s, c, index);
	tmp = ignorechr(s, c);
	ft_memcheck((res = (char **)malloc(length_tot + 1)));
	while (index[0] < length_tot)
	{
		length_word = len_word(tmp, c, index + 1);
		ft_memcheck((res[index[0]] =
			(char *)malloc(sizeof(char) * (length_word + 1))));
		while (index[1] < length_word)
			res[index[0]][index[1]++] = *(tmp++);
		res[index[0]++][index[1]] = 0;
		tmp = ignorechr(tmp, c);
	}
	res[index[0]] = 0;
	return (res);
}
