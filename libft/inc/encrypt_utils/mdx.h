/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:10:17 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 14:35:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MDX_H
#define MDX_H

#include "libft.h"

typedef	struct				s_mdx
{
	uint8_t					*msg;
	uint32_t				hash[4];
	uint32_t				a;
	uint32_t				b;
	uint32_t				c;
	uint32_t				d;
	size_t					new_len;
	uint32_t				*k;
	uint32_t				*s;
	uint32_t				*t;
	uint32_t				(*f[4])(uint32_t, uint32_t, uint32_t);
	size_t					nb_rounds;
	t_bool					add_b;
}							t_mdx;

void						process_mdx(t_mdx *mdx);
char						*build_final_hash_after_process(t_mdx *mdx);

t_mdx						*ft_md5_init(char *str);
t_mdx						*ft_md4_init(char *str);
char						*ft_mdx_buildfinal_n_free(t_mdx **mdx);

uint32_t					ft_md5_f(uint32_t x, uint32_t y, uint32_t z);
uint32_t					ft_md5_g(uint32_t x, uint32_t y, uint32_t z);
uint32_t					ft_md5_h(uint32_t x, uint32_t y, uint32_t z);
uint32_t					ft_md5_i(uint32_t x, uint32_t y, uint32_t z);

uint32_t					ft_md4_f(uint32_t x, uint32_t y, uint32_t z);
uint32_t					ft_md4_g(uint32_t x, uint32_t y, uint32_t z);
uint32_t					ft_md4_h(uint32_t x, uint32_t y, uint32_t z);

extern uint32_t				g_md5_kk[];
extern uint32_t				g_md5_ss[];
extern uint32_t				g_md5_tt[];

extern uint32_t				g_md4_kk[];
extern uint32_t				g_md4_ss[];
extern uint32_t				g_md4_tt[];

#endif
