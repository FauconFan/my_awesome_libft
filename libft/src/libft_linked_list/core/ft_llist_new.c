/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:35:52 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 13:31:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist					*ft_llist_new(
									void (*free_f)(void *elem))
{
	t_llist		*res;

	ft_memcheck((res = (t_llist *)malloc(sizeof(t_llist))));
	res->datas = NULL;
	res->copy_on_add = FALSE;
	res->len = 0;
	res->free = free_f;
	res->cpy = NULL;
	res->cmp = NULL;
	return res;
}
