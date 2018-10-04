/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:51:42 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 13:58:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_sha256(uint8_t *msg, size_t len)
{
	t_sha256	*sha256;
	char		*res;

	sha256 = ft_sha256_init(msg, len);
	ft_sha256_process(sha256);
	res = ft_sha256_buildfinal_n_free(&sha256);
	return (res);
}
