/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:12:04 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 18:01:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		merge_next(
		t_llist_elem *actu,
		void *data,
		int (*cmp_f)(void *d1, void *d2))
{
	t_llist_elem	*tmp;

	if (actu->next == 0)
		actu->next = ft_llist_elem_new(data);
	else
	{
		if (cmp_f(actu->next->content, data) > 0)
		{
			tmp = actu->next;
			actu->next = ft_llist_elem_new(data);
			actu->next->next = tmp;
		}
		else
			merge_next(actu->next, data, cmp_f);
	}
}

void			ft_llist_merge(t_llist *lst, void *data)
{
	t_llist_elem	*tmp;

	if (lst == NULL)
		return ;
	if (lst->datas == NULL)
		lst->datas = ft_llist_elem_new(data);
	else
	{
		if ((lst->cmp)(lst->datas->content, data) > 0)
		{
			tmp = lst->datas;
			lst->datas = ft_llist_elem_new(data);
			lst->datas->next = tmp;
		}
		else
		{
			merge_next(lst->datas, data, lst->cmp);
		}
	}
}
