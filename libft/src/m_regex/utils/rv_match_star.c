/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rv_match_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:37:49 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 15:52:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		rv_match_star(char *str, char *pattern)
{
	int		actu;

	if (pattern[0] != '*' || pattern[1] == '\0')
		return FALSE;
	if (pattern[1] == '.')
	{
		if (*str == '\0')
			return rv_match(str, pattern + 2);
		return rv_match_star(str + 1, pattern) || rv_match(str, pattern + 2);
	}
	else if (is_starting_group(pattern[1]))
	{
		ft_printf("%s\n", str);
		actu = rv_match_group(str, pattern + 1);
		if (actu < 0)
			return FALSE;
		if (actu == 0)
			return rv_match(str, rv_get_after_group(pattern + 1));
		return rv_match_star(str + actu, pattern) || rv_match(str, rv_get_after_group(pattern + 1));
	}
	if (pattern[1] != *str)
		return rv_match(str, pattern + 2);
	return rv_match_star(str + 1, pattern) || rv_match(str, pattern + 2);
}
