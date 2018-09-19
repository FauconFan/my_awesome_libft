/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:39:23 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/30 10:00:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA1_H
#define SHA1_H

#include "libft.h"

typedef struct		s_sha1
{
	uint8_t			*msg;
	uint32_t		hash[5];
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	size_t			new_len;
	uint32_t		*k;
	uint32_t		(*func_sha1[4])(uint32_t, uint32_t, uint32_t);
}					t_sha1;

t_sha1				*ft_sha1_init(uint8_t *msg, size_t len);
void				ft_sha1_process(t_sha1 *sha1);
char				*ft_sha1_buildfinal_n_free(t_sha1 **sha);

extern uint32_t		g_sha1_kk[];

#endif
