/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rv_match_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 10:20:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 17:59:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*rv_get_next_pattern(char *pattern)
{
	if (is_starting_group(*pattern))
		return (rv_get_after_group(pattern));
	else if (*pattern == '\\')
		return (pattern + 2);
	return (pattern + 1);
}

t_bool				rv_match_more(char *str, char *pattern, int min, int max)
{
	int		actu;

	if (*pattern == '\0')
		return (FALSE);
	if (min <= 0 && rv_match(str, rv_get_next_pattern(pattern)))
		return (TRUE);
	else if (max == 0)
		return (FALSE);
	else if (is_starting_group(*pattern))
	{
		actu = rv_match_group(str, pattern);
		if (actu <= 0)
			return (FALSE);
		else if (max == -1)
			return (rv_match_more(str + actu, pattern, min - 1, -1));
		return (rv_match_more(str + actu, pattern, min - 1, max - 1));
	}
	else
	{
		if ((actu = rv_match_character_rank(str, pattern)) == 0)
			return (FALSE);
		else if (max == -1)
			return (rv_match_more(str + 1, pattern, min - 1, -1));
		return (rv_match_more(str + 1, pattern, min - 1, max - 1));
	}
}
