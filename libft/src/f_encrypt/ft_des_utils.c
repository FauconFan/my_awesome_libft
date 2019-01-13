/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 09:08:05 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 22:39:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ft_des_config		g_des_config_tables[] =
{
	{ECB, FALSE, TRUE, ft_des_ecb_enc, ft_des_ecb_dec},
	{CBC, TRUE, TRUE, ft_des_cbc_enc, ft_des_cbc_dec},
	{PCBC, TRUE, TRUE, ft_des_pcbc_enc, ft_des_pcbc_dec},
	{CFB, TRUE, FALSE, ft_des_cfb_enc, ft_des_cfb_dec},
	{OFB, TRUE, FALSE, ft_des_ofb_enc, ft_des_ofb_dec},
};

size_t				g_size_des_config_tables =
	sizeof(g_des_config_tables) / sizeof(*g_des_config_tables);

uint8_t				*(*get_des_func(t_enc_mode mode, t_enc_action action))
						(t_des *des, uint8_t *msg, size_t size)
{
	size_t	i;

	i = 0;
	while (i < g_size_des_config_tables)
	{
		if (g_des_config_tables[i].mode == mode)
		{
			if (action == ENCRYPT)
				return (g_des_config_tables[i].f_ptr_encrypt);
			return (g_des_config_tables[i].f_ptr_decrypt);
		}
		i++;
	}
	return (NULL);
}

char				*ft_get_des_action_string(t_enc_mode mode)
{
	if (mode == ECB)
		return ("ECB");
	else if (mode == CBC)
		return ("CBC");
	else if (mode == PCBC)
		return ("PCBC");
	else if (mode == CFB)
		return ("CFB");
	else if (mode == OFB)
		return ("OFB");
	return (NULL);
}

t_bool				ft_need_iv(t_enc_mode mode)
{
	size_t	i;

	i = 0;
	while (i < g_size_des_config_tables)
	{
		if (g_des_config_tables[i].mode == mode)
		{
			return (g_des_config_tables[i].need_iv);
		}
		i++;
	}
	return (FALSE);
}

t_bool				ft_des_do_pad(t_enc_mode mode)
{
	size_t	i;

	i = 0;
	while (i < g_size_des_config_tables)
	{
		if (g_des_config_tables[i].mode == mode)
		{
			return (g_des_config_tables[i].do_pad);
		}
		i++;
	}
	return (FALSE);
}
