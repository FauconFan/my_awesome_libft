/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_384.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:39:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/30 10:01:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_H
#define SHA512_H

#include "libft.h"

typedef struct		s_sha512
{
	uint8_t			*msg;
	uint64_t		hash[8];
	uint64_t		a;
	uint64_t		b;
	uint64_t		c;
	uint64_t		d;
	uint64_t		e;
	uint64_t		f;
	uint64_t		g;
	uint64_t		h;
	size_t			new_len;
	uint64_t		*k;
}					t_sha512;

typedef t_sha512	t_sha384;

t_sha512			*ft_sha512_init(uint8_t *msg, size_t len);
void				ft_sha512_process(t_sha512 *sh);
char				*ft_sha512_buildfinal_n_free(t_sha512 **sha);

t_sha384			*ft_sha384_init(uint8_t *msg, size_t len);
char				*ft_sha384_buildfinal_n_free(t_sha384 **sha);

t_sha512			*ft_sha512_256_init(uint8_t *msg, size_t len);
char				*ft_sha512_256_buildfinal_n_free(t_sha512 **sha);

t_sha512			*ft_sha512_224_init(uint8_t *msg, size_t len);
char				*ft_sha512_224_buildfinal_n_free(t_sha512 **sha);

void				ft_sha512_free(t_sha512 **sha);

extern uint64_t		g_sha512_kk[];

#endif
