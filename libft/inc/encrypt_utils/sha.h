/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:53:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 14:34:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_H
#define SHA_H

#include "libft.h"

typedef struct		s_sha
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
	uint32_t		(*func_sha1[4])(uint32_t, uint32_t, uint32_t);
}					t_sha;

t_sha			*ft_sha1_init(char *msg);
char			*ft_sha1_buildfinal_n_free(t_sha **sha);

void			ft_sha_free(t_sha **sha);

uint32_t		ft_sha_ch_32(uint32_t x, uint32_t y, uint32_t z);
uint32_t		ft_sha_maj_32(uint32_t x, uint32_t y, uint32_t z);
uint32_t		ft_sha_parity_32(uint32_t x, uint32_t y, uint32_t z);

extern uint32_t		g_sha1_kk[];

#endif
