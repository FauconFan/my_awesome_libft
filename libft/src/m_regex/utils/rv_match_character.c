/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rv_match_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 10:24:53 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 17:59:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool		match_charactere_word(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z') || c == '_');
}

int					rv_match_character_rank(char *str, char *pattern)
{
	if (*pattern == '.' && *str == '\0')
		return (0);
	else if (*pattern == '.' && *str != '\0')
		return (1);
	else if (*pattern == '\\')
	{
		if (pattern[1] == 'd')
		{
			if (*str >= '0' && *str <= '9')
				return (2);
			return (0);
		}
		else if (pattern[1] == 'w')
		{
			if (match_charactere_word(*str))
				return (2);
			return (0);
		}
		else if (*str != ft_escapedtochar(pattern))
			return (0);
		return (2);
	}
	else if (*str == *pattern)
		return (1);
	return (0);
}

t_bool				rv_match_character(char *str, char *pattern)
{
	int		actu;

	actu = rv_match_character_rank(str, pattern);
	if (actu == 0)
		return (FALSE);
	return (rv_match(str + 1, pattern + actu));
}
