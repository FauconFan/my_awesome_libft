/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_str.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:20:28 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 16:48:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_STR_H
# define F_STR_H

# include "libft.h"

char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, size_t n);

char			*ft_strnew(size_t size);
char			*ft_strsetnew(int len, char c);

size_t			ft_strlen(char const *str);

int				ft_atoi(char const *nptr);
int				ft_atoi_base(char const *str, char *base);
long long		ft_atoll(char const *nptr);
long long		ft_atoll_base(char const *str, char *base);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, char *base);
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

char			*ft_lltoa_base(long long n, char *base);
char			*ft_ulltoa_base(unsigned long long n, char *base);

char			ft_escapedtochar(char *str);

void			ft_switch_endian(char *str);
void			ft_switch_endian_fixed(char *str, size_t len);

uint8_t			*ft_from_str_hex_to_array_num(char *str, size_t *len_res);

void			ft_strrev(char *str);

int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t size);

t_bool			ft_strequ(char *s1, char *s2);
t_bool			ft_strnequ(char *s1, char *s2);

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

int				ft_strcpos(char *s, int c);
int				ft_strcrpos(char *s, int c);
int				ft_strpos(char *big, char *little);
int				ft_strrpos(char *big, char *little);

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
t_bool			ft_str_is_xdigit(char *s);

t_bool			ft_str_contains_c(char *str, char c);

char			*ft_strdeleteif(char *str, t_bool (*f)(int c));

#endif
