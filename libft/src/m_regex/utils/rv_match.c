/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rv_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:36:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/12 11:55:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool		handle_solo_group(char *str, char *pattern)
{
	int		rank;

	rank = rv_match_group(str, pattern);
	if (rank <= 0)
		return FALSE;
	return rv_match(str + rank, rv_get_after_group(pattern));
}

static int			read_reverse_nb(char **pattern)
{
	int		e;
	int		res;
	char	*str;

	e = 1;
	res = 0;
	str = *pattern;
	while (ft_isdigit(*str))
	{
		res += e * (*str - '0');
		e *= 10;
		str++;
	}
	*pattern = str;
	return res;
}

static t_bool		handle_more(char *str, char *pattern)
{
	int		min;
	int		max;

	if (*pattern == '*')
		return rv_match_more(str, pattern + 1, 0, -1);
	else if (*pattern == '+')
		return rv_match_more(str, pattern + 1, 1, -1);
	else if (*pattern == '?')
		return rv_match_more(str, pattern + 1, 0, 1);
	else if (*pattern == '}')
	{
		pattern++;
		min = 0;
		max = -1;
		if (*pattern != '{')
		{
			if (*pattern != ',')
			{
				max = read_reverse_nb(&pattern);
				if (*pattern == '{')
					min = max;
			}
			if (*pattern == ',')
			{
				pattern++;
				min = read_reverse_nb(&pattern);
			}
			if (*pattern != '{' || (max != -1 && min > max))
				return FALSE;
		}
		else
			return FALSE;
		return rv_match_more(str, pattern + 1, min, max);
	}
	return FALSE;
}

t_bool				rv_match(char *str, char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return TRUE;
	else if (*pattern == '*' || *pattern == '+'
			|| *pattern == '?' || *pattern == '}')
		return handle_more(str, pattern);
	else if (is_starting_group(*pattern))
		return handle_solo_group(str, pattern);
	else if (*str == '\0' || *pattern == '\0')
		return FALSE;
	return rv_match_character(str, pattern);
}
