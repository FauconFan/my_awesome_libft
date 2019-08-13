/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strlambda.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 10:55:05 by pepe              #+#    #+#             */
/*   Updated: 2019/08/13 18:20:10 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRLAMBDA_H
# define LIBFT_STRLAMBDA_H

# include <stddef.h>
# include "common.h"

t_bool		ft_strall(const char *s, t_bool (*f)(int c));
t_bool		ft_strany(const char *s, t_bool (*f)(int c));
void		ft_striter(const char *s, void (*f)(const char *));
void		ft_striteri(const char *s, void (*f)(unsigned int, const char *));
char		*ft_strmap(const char *s, char (*f)(char));
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

#endif
