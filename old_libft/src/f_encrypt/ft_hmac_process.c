/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmac_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:35:51 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 13:57:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_hmac_step(
					t_hmac *hmac,
					uint8_t *prefix,
					uint8_t *text,
					size_t len_text)
{
	char	*res;
	uint8_t	*tmp;
	size_t	len;

	len = hmac->size_block + len_text;
	tmp = (uint8_t *)ft_strnew(len);
	ft_memcpy(tmp, prefix, hmac->size_block);
	ft_memcpy(tmp + hmac->size_block, text, len_text);
	res = hmac->hash_f(tmp, len);
	free(tmp);
	return (res);
}

static uint8_t	*prepare_key_pad(t_hmac *hmac, char c)
{
	uint8_t		*pad;
	size_t		i;

	pad = (uint8_t *)ft_strsetnew(hmac->size_block, c);
	i = 0;
	while (i < hmac->size_block)
	{
		pad[i] = pad[i] ^ hmac->key[i];
		i++;
	}
	return (pad);
}

char			*ft_hmac_process(t_hmac *hmac, uint8_t *msg, size_t len_msg)
{
	uint8_t		*pad;
	char		*tmp;
	uint8_t		*tmp2;
	size_t		size_tmp2;
	char		*res;

	(void)msg;
	(void)len_msg;
	pad = prepare_key_pad(hmac, IPAD_CHAR);
	tmp = ft_hmac_step(hmac, pad, msg, len_msg);
	tmp2 = ft_from_str_hex_to_array_num(tmp, &size_tmp2);
	free(pad);
	free(tmp);
	pad = prepare_key_pad(hmac, OPAD_CHAR);
	res = ft_hmac_step(hmac, pad, tmp2, size_tmp2);
	free(pad);
	free(tmp2);
	return (res);
}
