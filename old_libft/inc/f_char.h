/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:17:44 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/15 16:05:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_CHAR_H
# define F_CHAR_H

# include "libft.h"

t_bool			ft_isalnum(int c);
t_bool			ft_isalpha(int c);
t_bool			ft_isdigit(int c);
t_bool			ft_isascii(int c);
t_bool			ft_isblank(int c);
t_bool			ft_isprint(int c);
t_bool			ft_iswhitespace(int c);
t_bool			ft_isspace(int c);
t_bool			ft_islower(int c);
t_bool			ft_isupper(int c);
t_bool			ft_isxdigit(int c);

int				ft_toupper(int c);
int				ft_tolower(int c);

char			ft_toxdigit(char c);
char			ft_gethexvalue(char c);

#endif
