/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strctype.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:10:24 by pepe              #+#    #+#             */
/*   Updated: 2019/08/13 18:17:16 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRCTYPE_H
# define LIBFT_STRCTYPE_H

# include "common.h"

t_bool		ft_stralnum(const char *s);
t_bool		ft_stralpha(const char *s);
t_bool		ft_strascii(const char *s);
t_bool		ft_strblank(const char *s);
t_bool		ft_strdigit(const char *s);
t_bool		ft_strlower(const char *s);
t_bool		ft_strprint(const char *s);
t_bool		ft_strupper(const char *s);
t_bool		ft_strxdigit(const char *s);

#endif
