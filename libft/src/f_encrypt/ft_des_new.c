/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:38:21 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/19 13:17:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_build_sub_keys(t_des *des, uint64_t original_key)
{
	uint64_t	c;
	uint64_t	d;
	size_t		i;

	c = (uint64_t)ft_des_apply_pc1_left(original_key);
	d = (uint64_t)ft_des_apply_pc1_right(original_key);
	i = 0;
	while (i < 16)
	{
		c = (c << g_des_shifts_subkeys[i] & 0xFFFFFFF)
			| ((c >> (28 - g_des_shifts_subkeys[i])) & 0xFFFFFFF);
		d = (d << g_des_shifts_subkeys[i] & 0xFFFFFFF)
			| ((d >> (28 - g_des_shifts_subkeys[i])) & 0xFFFFFFF);
		des->key_n[i] = ft_des_apply_pc2(c, d);
		des->key_n_rev[15 - i] = des->key_n[i];
		i++;
	}
}

t_des			*ft_des_new(
							uint64_t original_key,
							uint64_t iv,
							t_enc_action action,
							t_enc_mode mode)
{
	t_des		*res;

	ft_memcheck((res = (t_des *)malloc(sizeof(t_des))));
	res->action = action;
	ft_build_sub_keys(res, original_key);
	res->iv = iv;
	res->mode = mode;
	return res;
}

void			ft_des_change_action(t_des *des, t_enc_action action)
{
	des->action = action;
}

void			ft_des_free(t_des **des)
{
	free(*des);
	*des = NULL;
}
