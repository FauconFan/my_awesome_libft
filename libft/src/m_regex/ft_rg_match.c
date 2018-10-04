/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rg_match.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:25:34 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 17:57:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool		reverse_esc(char *s)
{
	while (*s)
	{
		if (*s == '\\')
		{
			if (s[1] == '\0')
				return (FALSE);
			s[0] = s[1];
			s[1] = '\\';
			s++;
		}
		s++;
	}
	return (TRUE);
}

t_bool				ft_rg_match(char *s1, char *s2)
{
	char	*str;
	char	*pattern;
	t_bool	res;

	str = ft_strdup(s1);
	pattern = ft_strdup(s2);
	res = FALSE;
	if (reverse_esc(pattern))
	{
		ft_strrev(str);
		ft_strrev(pattern);
		ft_putendl(str);
		ft_putendl(pattern);
		res = rv_match(str, pattern);
		ft_printf("res %d\n", res);
	}
	ft_strdel(&str);
	ft_strdel(&pattern);
	return (res);
}
