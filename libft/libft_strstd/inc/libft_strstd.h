/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strstd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 10:26:59 by pepe              #+#    #+#             */
/*   Updated: 2019/08/13 16:36:07 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRSTD_H
# define LIBFT_STRSTD_H

# include <stdlib.h>
# include <stddef.h>
# include "common.h"

/*
**	Alloc
*/

char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);

char			*ft_strnew(size_t size);
char			*ft_strsetnew(size_t len, char c);

/*
**	Analyze
*/

int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t size);

t_bool			ft_strequ(char *s1, char *s2);
t_bool			ft_strnequ(char *s1, char *s2);

int				ft_strpos(char *big, char *little);
int				ft_strrpos(char *big, char *little);

int				ft_strcpos(char *s, int c);
int				ft_strcrpos(char *s, int c);

const char		*ft_strstr(const char *haystack, const char *needle);
const char		*ft_strnstr(const char *haystack, const char *needle,
										size_t len);

size_t			ft_strlen(char const *str);

/*
**	Process
*/

char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, char *src, size_t nb);

const char		*ft_strchr(const char *s, int c);
const char		*ft_strrchr(const char *s, int c);

char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);

void			ft_strclr(char *s);

void			ft_strrev(char *str);

char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);

#endif
