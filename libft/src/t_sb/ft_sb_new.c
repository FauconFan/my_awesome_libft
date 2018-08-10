/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 10:54:43 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 11:43:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sb		*ft_sb_new()
{
	t_sb	*res;

	res = ft_slist_new(free);
	ft_slist_add_cpy(res, MAKE_COPY_PTR(ft_strdup));
	return res;
}
