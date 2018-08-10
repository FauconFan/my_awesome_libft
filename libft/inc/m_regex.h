/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_regex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:38:22 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 15:56:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_REGEX_H
#define M_REGEX_H

#include "libft.h"

t_bool				ft_match(char *s1, char *s2);

/*
**	Utils
*/

t_bool				rv_match(char *str, char *pattern);
t_bool				rv_match_star(char *str, char *pattern);
t_bool				rv_match_plus(char *str, char *pattern);
t_bool				rv_match_questionmark(char *str, char *pattern);

int					rv_match_group(char *str, char *pattern);
char				*rv_get_after_group(char *pattern);

t_bool				is_starting_group(char c);

#endif
