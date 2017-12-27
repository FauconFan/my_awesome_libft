/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:20:43 by pepe              #+#    #+#             */
/*   Updated: 2017/12/27 13:20:37 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_custom.h"

void	bc_update_str_still(char **str, int (*f)(char c))
{
	char	*tmp;

	tmp = *str;
	while (f(*tmp) != 0 && *tmp != 0)
		tmp++;
	*str = tmp;
}

void	bc_update_str_until(char **str, int (*f)(char c))
{
	char	*tmp;

	tmp = *str;
	while (f(*tmp) == 0 && *tmp != 0)
		tmp++;
	*str = tmp;
}

void	bc_update_str_stillstr(char **str, int (*f)(char *c))
{
	char	*tmp;

	tmp = *str;
	while (f(tmp) != 0 && *tmp != 0)
		tmp++;
	*str = tmp;
}

void	bc_update_str_untilstr(char **str, int (*f)(char *c))
{
	char	*tmp;

	tmp = *str;
	while (f(tmp) == 0 && *tmp != 0)
		tmp++;
	*str = tmp;
}

char	*bc_strdup(char *str)
{
	char			*res;
	unsigned int	index;
	unsigned int	size;

	size = strlen(str);
	if ((res = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		exit(1);
	index = 0;
	while (str[index] != 0)
	{
		res[index] = str[index];
		index++;
	}
	res[index] = 0;
	return (res);
}

char	*bc_strndup(char *str, unsigned int size)
{
	char			*res;
	unsigned int	index;

	if ((res = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		exit(1);
	index = 0;
	while (index < size && str[index] != 0)
	{
		res[index] = str[index];
		index++;
	}
	while (index < size + 1)
	{
		res[index] = 0;
		index++;
	}
	return (res);
}

char	*bc_strjoin(char *s1, char *s2)
{
	char	*res;
	int		l1;
	int		l2;

	l1 = strlen(s1);
	l2 = strlen(s2);
	if ((res = (char *)malloc(sizeof(char) * (l1 + l2 + 1))) == 0)
		exit(1);
	l1 = 0;
	l2 = 0;
	while (s1[l1])
	{
		res[l1] = s1[l1];
		l1++;
	}
	while (s2[l2])
	{
		res[l1 + l2] = s2[l2];
		l2++;
	}
	res[l1 + l2] = 0;
	return (res);
}

char	*bc_strjoin_folder(char *s1, char *s2)
{
	char	*res;
	int		l1;
	int		l2;

	l1 = strlen(s1);
	l2 = strlen(s2);
	if ((res = (char *)malloc(sizeof(char) * (l1 + l2 + 2))) == 0)
		exit(1);
	l1 = 0;
	l2 = 0;
	while (s1[l1])
	{
		res[l1] = s1[l1];
		l1++;
	}
	res[l1] = '/';
	while (s2[l2])
	{
		res[l1 + 1 + l2] = s2[l2];
		l2++;
	}
	res[l1 + 1 + l2] = 0;
	return (res);
}

int		bc_normalize_absolute_path(char *res)
{
	int		size;
	int		index;

	size = 1;
	while (res[size] != 0 && (res[size] != '/' || size++))
	{
		if (strncmp(res + size, "../", 3) == 0)
		{
			size--;
			index = 4;
			while (--size >= 0 && res[size] != '/')
				index++;
			if (size < 0)
				return (1);
			strncpy(res + size, res + size + index,
						strlen(res + size + index) + 1);
		}
		else if (strncmp(res + size, "./", 2) == 0)
			strncpy(res + size, res + size + 2,
							strlen(res + size + 2) + 1);
		else
			while (res[size] != '/' && res[size] != 0)
				size++;
	}
	return (0);
}
