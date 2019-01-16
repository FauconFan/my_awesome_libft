/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:25:20 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/16 23:05:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint8_t		*table_assoc(t_des *des, uint8_t *msg, size_t size)
{
	uint8_t		*(*f_ptr)(t_des *des, uint8_t *msg, size_t size);

	f_ptr = get_des_func(des->mode, des->action);
	if (f_ptr == NULL)
	{
		ft_dprintf(2, "Never should happened\n");
		return (NULL);
	}
	return (f_ptr(des, msg, size));
}

static void			delete_pad(uint8_t *res, size_t *size)
{
	size_t	bit;
	size_t	i;

	bit = res[*size - 1];
	i = *size - bit;
	while (i < *size)
	{
		res[i] = 0;
		i++;
	}
	*size -= bit;
}

uint8_t				*ft_des_process(
						t_des *des,
						uint8_t *msg,
						size_t size_in,
						size_t *size_out)
{
	uint8_t		*res;
	uint8_t		*new_msg;

	if (des->do_pad && des->action == ENCRYPT)
	{
		*size_out = ((size_in / 8) + 1) * 8;
		new_msg = (uint8_t *)ft_strndup((char *)msg, *size_out);
		ft_des_append_padding(new_msg + size_in, *size_out - size_in);
	}
	else
	{
		*size_out = (size_in % 8) ? (size_in + (8 - (size_in % 8))) : size_in;
		new_msg = ft_memalloc(*size_out + 1);
		ft_memcpy(new_msg, msg, size_in);
	}
	res = table_assoc(des, new_msg, *size_out);
	if (des->do_pad)
	{
		if (des->action != ENCRYPT)
			delete_pad(res, size_out);
	}
	free(new_msg);
	return (res);
}
