/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:35:52 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 16:41:46 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist						*ft_llist_new(
										void (*free_f)(void *elem),
										int (*cmp_f)(void *d1, void *d2))
{
	t_llist		*res;

	if (free_f == NULL)
		return NULL;
	ft_memcheck((res = (t_llist *)malloc(sizeof(t_llist))));
	res->datas = NULL;
	res->free = free_f;
	res->cmp = cmp_f;
	return res;
}
