/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rv_match_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:43:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/12 11:50:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	rv_match_group_char(char *str, char *pattern)
{
	t_bool	find;
	int		actu;

	find = FALSE;
	while (*pattern && *pattern != '[')
	{
		actu = 1;
		if (*str != '^')
		{
			actu = rv_match_character_rank(str, pattern);
			if (actu > 0)
				find = TRUE;
		}
		pattern = pattern + (int)ft_max(actu, 1);
	}
	if (*pattern == 0)
		return (-1);
	if ((pattern[-1] == '^' && !find) || (pattern[-1] != '^' && find))
		return 1;
	return 0;
}

static int	rv_match_group_string(char *str, char *pattern)
{
	int		rank;

	rank = ft_strcpos(pattern, '(');
	if (rank <= 0)
		return (-1);
	pattern[rank] = '\0';
	while ((rank = ft_strcpos(pattern, '|')) != -1)
	{
		if (rank == 0)
			return (-1);
		if (ft_strncmp(str, pattern, rank) == 0)
		{
			pattern[ft_strlen(pattern)] = '(';
			return rank;
		}
		pattern += rank + 1;
	}
	rank = ft_strlen(pattern);
	if (ft_strncmp(str, pattern, rank) == 0)
	{
		pattern[rank] = '(';
		return rank;
	}
	pattern[rank] = '(';
	return (0);
}

int			rv_match_group(char *str, char *pattern)
{
	if (*str == '\0')
		return 0;
	if (*pattern == ']')
	{
		pattern++;
		return (rv_match_group_char(str, pattern));
	}
	else if (*pattern == ')')
	{
		pattern++;
		return (rv_match_group_string(str, pattern));
	}
	return -1;
}

char		*rv_get_after_group(char *pattern)
{
	if (*pattern == ']')
	{
		while (*pattern && *pattern != '[')
			pattern++;
		if (*pattern == 0)
			return NULL;
		return pattern + 1;
	}
	else if (*pattern == ')')
	{
		while (*pattern && *pattern != '(')
			pattern++;
		if (*pattern == 0)
			return NULL;
		return pattern + 1;
	}
	return pattern;
}

t_bool		is_starting_group(char c)
{
	return c == ']' || c == ')';
}
