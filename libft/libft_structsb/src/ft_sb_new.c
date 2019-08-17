/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 10:54:43 by jpriou            #+#    #+#             */
/*   Updated: 2019/08/17 12:08:21 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structsb.h"
#include "libft_strstd.h"

t_sb		*ft_sb_new(void)
{
	t_sb	*res;

	res = ft_slist_new(free);
	ft_slist_add_cpy(res, (void *(*)(void *))(ft_strdup));
	return (res);
}
