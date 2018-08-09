/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:35:43 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:10:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist			*ft_llist_cpy(t_llist *lst)
{
	t_llist		*res;

	res = ft_llist_map(lst, lst->cpy, lst->free);
	res->copy_on_add = lst->copy_on_add;
	res->len = lst->len;
	res->free = lst->free;
	res->cpy = lst->cpy;
	res->cmp = lst->cmp;
	return res;
}
