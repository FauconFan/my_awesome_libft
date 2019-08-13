/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:44:54 by pepe              #+#    #+#             */
/*   Updated: 2019/08/13 16:30:02 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_bzero(void *s, size_t n);
void			ft_memcheck(void *ptr);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
const void		*ft_memchr(const void *s, int c, size_t n);
void			*ft_memdup(void *d, size_t len);
void			*ft_memndup(void *d, size_t len, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memprint(void *v, size_t len);

void			ft_switch_endian(uint8_t *str, size_t len);

#endif
