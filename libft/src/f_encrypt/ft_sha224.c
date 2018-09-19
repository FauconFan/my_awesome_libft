/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha224.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:51:42 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/30 09:58:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_sha224(uint8_t *msg, size_t len)
{
	t_sha224	*sha224;
	char		*res;

	sha224 = ft_sha224_init(msg, len);
	ft_sha256_process(sha224);
	res = ft_sha224_buildfinal_n_free(&sha224);
	return res;
}
