/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rv_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:36:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 15:57:49 by jpriou           ###   ########.fr       */
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

t_bool				rv_match(char *str, char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return TRUE;
	else if (*str != '\0' && *pattern == '\0')
		return FALSE;
	else if (*pattern == '.' && *str == '\0')
		return FALSE;
	else if (*pattern == '.' && *str != '\0')
		return rv_match(str + 1, pattern + 1);
	else if (*pattern == '*')
		return rv_match_star(str, pattern);
	else if (*pattern == '+')
		return rv_match_plus(str, pattern);
	else if (*pattern == '?')
		return rv_match_questionmark(str, pattern);
	else if (is_starting_group(*pattern))
		return handle_solo_group(str, pattern);
	else if (*str == '\0' && *pattern != '\0')
		return FALSE;
	else if (*str == *pattern)
		return rv_match(str + 1, pattern + 1);
	return FALSE;
}
