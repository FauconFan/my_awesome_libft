/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:35:52 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 18:03:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slist					*ft_slist_new(void (*free_f)(void *elem))
{
	t_slist		*res;

	ft_memcheck((res = (t_slist *)malloc(sizeof(t_slist))));
	res->head = NULL;
	res->len = 0;
	res->free = free_f;
	res->cpy = NULL;
	res->cmp = NULL;
	return (res);
}
