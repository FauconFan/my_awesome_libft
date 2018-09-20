/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memmory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:21:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/09/20 09:59:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_MEMMORY_H
#define F_MEMMORY_H

#include "libft.h"

void			ft_die(char *error_message);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_bzero(void *s, size_t n);
void			ft_memcheck(void *ptr);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memdup(void *d, size_t len);
void			*ft_memndup(void *d, size_t len, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memprint(void *v, size_t len);

#endif
