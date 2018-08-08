/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:28:25 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/08 16:15:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_blank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int		check_only_blank(char *tmp)
{
	while (*tmp)
	{
		if (is_blank(*tmp) == 0)
			return (1);
		tmp++;
	}
	return (0);
}

static size_t	true_size(char *s)
{
	size_t	real_size;

	real_size = 0;
	while (s[real_size])
		real_size++;
	real_size--;
	while (is_blank(s[real_size]))
		real_size--;
	real_size++;
	return (real_size);
}

char			*ft_strtrim(const char *s)
{
	char	*tmp;
	char	*res;
	size_t	real_size;
	size_t	index;

	tmp = (char *)s;
	res = 0;
	index = 0;
	if (s == 0)
		return (0);
	if (check_only_blank((char *)s) == 0)
		return (ft_strnew(0));
	while (is_blank(*tmp))
		tmp++;
	real_size = true_size(tmp);
	ft_memcheck((res = (char *)malloc(sizeof(char) * (real_size + 1))));
	while (index < real_size)
	{
		res[index] = tmp[index];
		index++;
	}
	res[index] = 0;
	return (res);
}
