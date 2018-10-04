/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512_224.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:51:42 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 13:58:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_sha512_224(uint8_t *msg, size_t len)
{
	t_sha512	*sha512;
	char		*res;

	sha512 = ft_sha512_224_init(msg, len);
	ft_sha512_process(sha512);
	res = ft_sha512_224_buildfinal_n_free(&sha512);
	return (res);
}
