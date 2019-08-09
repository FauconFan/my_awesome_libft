/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_regex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:38:22 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 11:45:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_REGEX_H
# define M_REGEX_H

# include "libft.h"

t_bool				ft_rg_match(char *s1, char *s2);

/*
**	Utils
*/

t_bool				rv_match(char *str, char *pattern);

t_bool				rv_match_more(char *str, char *pattern, int min, int max);

int					rv_match_character_rank(char *str, char *pattern);
t_bool				rv_match_character(char *str, char *pattern);

int					rv_match_group(char *str, char *pattern);
char				*rv_get_after_group(char *pattern);

t_bool				is_starting_group(char c);

#endif
