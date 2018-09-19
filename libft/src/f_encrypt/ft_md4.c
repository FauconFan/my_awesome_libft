/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:48:49 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/30 10:02:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_md4(uint8_t *str, size_t len)
{
	t_mdx		*md4;
	char		*res;

	md4 = ft_md4_init(str, len);
	process_mdx(md4);
	res = ft_mdx_buildfinal_n_free(&md4);
	return res;
}
