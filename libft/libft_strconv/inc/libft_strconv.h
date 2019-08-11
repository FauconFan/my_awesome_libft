/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strconv.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 10:55:05 by pepe              #+#    #+#             */
/*   Updated: 2019/08/11 11:13:17 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRCONV_H
# define LIBFT_STRCONV_H

# include <stddef.h>
# include <stdint.h>
# include "common.h"

/*
**	num
*/

int				ft_atoi(char const *nptr);
int				ft_atoi_base(char const *str, char *base);
long long		ft_atoll(char const *nptr);
long long		ft_atoll_base(char const *str, char *base);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, char *base);
char			*ft_lltoa(long long n);
char			*ft_lltoa_base(long long n, char *base);
char			*ft_ulltoa(unsigned long long n);
char			*ft_ulltoa_base(unsigned long long n, char *base);

char			*ft_convert_base(char *nbr, char *base_from, char *base_to);

uint8_t			*ft_str_hex_to_array_num(char *str, size_t *len_res);

char			*ft_str_toupper(char *str);
char			*ft_str_tolower(char *str);

char			*ft_escape(char *str);
char			*ft_unescape(char *str);

#endif
