/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:35:43 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 18:03:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist			*ft_slist_cpy(t_slist *lst)
{
	t_slist		*res;

	res = ft_slist_map(lst, lst->cpy, lst->free);
	res->len = lst->len;
	res->free = lst->free;
	res->cpy = lst->cpy;
	res->cmp = lst->cmp;
	return (res);
}
