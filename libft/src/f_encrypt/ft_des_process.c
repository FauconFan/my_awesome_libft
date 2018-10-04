/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:25:20 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 13:59:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint8_t		*table_assoc(t_des *des, uint8_t *msg, size_t size)
{
	if (des->mode == ECB && des->action == ENCRYPT)
		return (ft_des_ecb_enc(des, msg, size));
	else if (des->mode == ECB && des->action == DECRYPT)
		return (ft_des_ecb_dec(des, msg, size));
	else if (des->mode == CBC && des->action == ENCRYPT)
		return (ft_des_cbc_enc(des, msg, size));
	else if (des->mode == CBC && des->action == DECRYPT)
		return (ft_des_cbc_dec(des, msg, size));
	else if (des->mode == PCBC && des->action == ENCRYPT)
		return (ft_des_pcbc_enc(des, msg, size));
	else if (des->mode == PCBC && des->action == DECRYPT)
		return (ft_des_pcbc_dec(des, msg, size));
	else if (des->mode == CFB && des->action == ENCRYPT)
		return (ft_des_cfb_enc(des, msg, size));
	else if (des->mode == CFB && des->action == DECRYPT)
		return (ft_des_cfb_dec(des, msg, size));
	else if (des->mode == OFB && des->action == ENCRYPT)
		return (ft_des_ofb_enc(des, msg, size));
	else if (des->mode == OFB && des->action == DECRYPT)
		return (ft_des_ofb_dec(des, msg, size));
	ft_dprintf(2, "Never should happened\n");
	return (NULL);
}

static void			delete_pad(uint8_t *res, size_t size)
{
	size_t	bit;
	size_t	i;

	bit = res[size - 1];
	i = size - bit;
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
}

uint8_t				*ft_des_process(
						t_des *des,
						uint8_t *msg,
						size_t size_in,
						size_t *size_out)
{
	t_bool		do_pad;
	uint8_t		*res;
	uint8_t		*new_msg;

	do_pad = TRUE;
	if (do_pad && des->action == ENCRYPT)
	{
		*size_out = ((size_in / 8) + 1) * 8;
		new_msg = (uint8_t *)ft_strndup((char *)msg, *size_out);
		ft_des_append_padding(new_msg + size_in, *size_out - size_in);
	}
	else
	{
		*size_out = size_in;
		new_msg = msg;
	}
	res = table_assoc(des, new_msg, *size_out);
	if (do_pad)
	{
		if (des->action == ENCRYPT)
			ft_strdel((char **)&new_msg);
		else
			delete_pad(res, *size_out);
	}
	return (res);
}
