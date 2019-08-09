/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:52:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 13:58:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_sha1(uint8_t *msg, size_t len)
{
	t_sha1	*sha1;
	char	*res;

	sha1 = ft_sha1_init(msg, len);
	ft_sha1_process(sha1);
	res = ft_sha1_buildfinal_n_free(&sha1);
	return (res);
}
