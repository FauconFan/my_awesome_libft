/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_224.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:39:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/30 10:01:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA256_H
#define SHA256_H

#include "libft.h"

typedef struct		s_sha256
{
	uint8_t			*msg;
	uint32_t		hash[8];
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
	size_t			new_len;
	uint32_t		*k;
}					t_sha256;

typedef t_sha256	t_sha224;

t_sha256			*ft_sha256_init(uint8_t *msg, size_t len);
void				ft_sha256_process(t_sha256 *sh);
char				*ft_sha256_buildfinal_n_free(t_sha256 **sha);


t_sha224			*ft_sha224_init(uint8_t *msg, size_t len);
char				*ft_sha224_buildfinal_n_free(t_sha224 **sha);

void				ft_sha256_free(t_sha256 **sha);

extern uint32_t		g_sha256_kk[];

#endif
