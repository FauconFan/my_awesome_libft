/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:08:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 10:57:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_llist_elem		*rec_tail(t_llist_elem *e1, t_llist_elem *e2)
{
	t_llist_elem	*next;

	if (e1 == NULL)
		return e2;
	next = e1->next;
	e1->next = e2;
	return rec_tail(next, e1);
}

void					ft_llist_rev(t_llist *lst)
{
	lst->datas = rec_tail(lst->datas, NULL);
}
