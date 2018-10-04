/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmac_init_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:57:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 13:57:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint8_t	*prepare_key(
					uint8_t *key,
					size_t len_key,
					char *(*hash_f)(uint8_t *, size_t),
					size_t size_block)
{
	uint8_t		*res;
	char		*tmp;
	uint8_t		*tmp2;
	size_t		new_len;

	ft_memcheck((res = (uint8_t *)malloc(sizeof(uint8_t) * size_block)));
	if (len_key <= size_block)
	{
		ft_memcpy(res, key, len_key);
		ft_memset(res + len_key, 0, size_block - len_key);
	}
	else
	{
		tmp = hash_f(key, len_key);
		tmp2 = ft_from_str_hex_to_array_num(tmp, &new_len);
		ft_memcpy(res, tmp2, new_len);
		ft_strdel(&tmp);
		free(tmp2);
		tmp2 = prepare_key(res, new_len, hash_f, size_block);
		free(res);
		res = tmp2;
	}
	return (res);
}

t_hmac			*ft_hmac_init(
					uint8_t *key,
					size_t len_key,
					char *(hash_f)(uint8_t *, size_t),
					size_t size_block)
{
	t_hmac		*res;

	ft_memcheck((res = (t_hmac *)malloc(sizeof(t_hmac))));
	res->key = prepare_key(key, len_key, hash_f, size_block);
	res->hash_f = hash_f;
	res->size_block = size_block;
	return (res);
}

void			ft_hmac_free(t_hmac **hmac)
{
	free((*hmac)->key);
	free(*hmac);
	*hmac = NULL;
}
