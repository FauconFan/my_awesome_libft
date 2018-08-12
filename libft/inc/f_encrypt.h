/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_encrypt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:50:41 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/12 21:52:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_ENCRYPT_H
#define F_ENCRYPT_H

#include "libft.h"

#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

typedef	struct				s_md5
{
	uint8_t					*msg;
	uint32_t				h[4];
	uint32_t				a;
	uint32_t				b;
	uint32_t				c;
	uint32_t				d;
	uint32_t				new_len;
}							t_md5;

char						*ft_md5(char *str);
t_md5						*ft_md5_init(char *str);
void						ft_md5_free(t_md5 **md5);

extern uint32_t				g_md5_r[];
extern uint32_t				g_md5_k[];

#endif
