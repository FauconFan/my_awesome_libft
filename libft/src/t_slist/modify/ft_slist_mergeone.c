/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_mergeone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:12:04 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:43:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		merge_next(
		t_slist_elem *actu,
		void *data,
		int (*cmp_f)(void *d1, void *d2))
{
	t_slist_elem	*tmp;

	if (actu->next == 0)
		actu->next = ft_slist_elem_new(data);
	else
	{
		if (cmp_f(actu->next->content, data) > 0)
		{
			tmp = actu->next;
			actu->next = ft_slist_elem_new(data);
			actu->next->next = tmp;
		}
		else
			merge_next(actu->next, data, cmp_f);
	}
}

void			ft_slist_merge_one(t_slist *lst, void *data)
{
	t_slist_elem	*tmp;

	if (lst == NULL)
		return ;
	lst->len = lst->len + 1;
	if (lst->head == NULL)
		lst->head = ft_slist_elem_new(data);
	else
	{
		if ((lst->cmp)(lst->head->content, data) > 0)
		{
			tmp = lst->head;
			lst->head = ft_slist_elem_new(data);
			lst->head->next = tmp;
		}
		else
		{
			merge_next(lst->head, data, lst->cmp);
		}
	}
}
