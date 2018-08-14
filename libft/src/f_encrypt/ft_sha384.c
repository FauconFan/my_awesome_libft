/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha384.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:51:42 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 17:22:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_sha384(char *msg)
{
	t_sha384	*sha384;
	char		*res;

	sha384 = ft_sha384_init(msg);
	ft_sha512_process(sha384);
	res = ft_sha384_buildfinal_n_free(&sha384);
	return res;
}
