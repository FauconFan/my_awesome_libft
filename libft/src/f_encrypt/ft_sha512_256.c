/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512_256.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:51:42 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/30 09:59:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_sha512_256(uint8_t *msg, size_t len)
{
	t_sha512	*sha512;
	char		*res;

	sha512 = ft_sha512_256_init(msg, len);
	ft_sha512_process(sha512);
	res = ft_sha512_256_buildfinal_n_free(&sha512);
	return res;
}
