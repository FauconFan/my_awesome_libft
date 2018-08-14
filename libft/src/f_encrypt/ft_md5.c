/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 15:48:49 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/13 14:37:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_md5(char *str)
{
	t_mdx		*md5;
	char		*res;

	md5 = ft_md5_init(str);
	process_mdx(md5);
	res = ft_mdx_buildfinal_n_free(&md5);
	return res;
}
