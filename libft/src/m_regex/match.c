/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:25:34 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 15:02:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool				ft_match(char *s1, char *s2)
{
	char	*str;
	char	*pattern;
	t_bool	res;

	str = ft_strdup(s1);
	pattern = ft_strdup(s2);
	ft_strrev(str);
	ft_strrev(pattern);
	ft_putendl(str);
	ft_putendl(pattern);
	res = rv_match(str, pattern);
	ft_printf("res %d\n", res);
	ft_strdel(&str);
	ft_strdel(&pattern);
	return res;
}
