/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:20:28 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/27 08:20:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
#define LIBFT_STR_H

#include "libft.h"

char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);

char			*ft_strnew(size_t size);
char			*ft_strsetnew(int len, char c);

size_t			ft_strlen(char const *str);

int				ft_atoi(char const *nptr);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, char *base);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

char			*ft_lltoa_base(long long n, char *base);
char			*ft_ulltoa_base(unsigned long long n, char *base);

int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t size);

char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);

char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, char *src, size_t nb);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);

char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
										size_t len);

void			ft_strdel(char **as);
void			ft_strclr(char *s);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

int				ft_strcpos(char *s, int c);
int				ft_strcrpos(char *s, int c);
int				ft_strpos(char *big, char *little);
int				ft_strrpos(char *big, char *little);

int				ft_strparse(char ***res, char *str, char c);
int				ft_strparse_n_free(char ***res, char *str, char c);

t_bool			ft_str_all(char *s, t_bool (*f)(int c));
t_bool			ft_str_any(char *s, t_bool (*f)(int c));

t_bool			ft_str_is_alnum(char *s);
t_bool			ft_str_is_alpha(char *s);
t_bool			ft_str_is_ascii(char *s);
t_bool			ft_str_is_numeric(char *s);
t_bool			ft_str_is_lowercase(char *s);
t_bool			ft_str_is_uppercase(char *s);
t_bool			ft_str_is_printable(char *s);
t_bool			ft_str_is_blank(char *s);

#endif