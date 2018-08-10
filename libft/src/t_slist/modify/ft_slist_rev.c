/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:08:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:42:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_slist_elem		*rec_tail(t_slist_elem *e1, t_slist_elem *e2)
{
	t_slist_elem	*next;

	if (e1 == NULL)
		return e2;
	next = e1->next;
	e1->next = e2;
	return rec_tail(next, e1);
}

void					ft_slist_rev(t_slist *lst)
{
	lst->head = rec_tail(lst->head, NULL);
}
