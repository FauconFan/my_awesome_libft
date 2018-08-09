/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:32:13 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:21:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		merging(void *elem, void *lst_ptr)
{
	t_llist		*lst;

	lst = (t_llist *)lst_ptr;
	ft_llist_merge_one(lst, elem);
}

static void		free_elem(t_llist_elem *head)
{
	if (head != NULL)
	{
		free_elem(head->next);
		free(head);
	}
}

void			ft_llist_sort(t_llist *lst)
{
	t_llist			*tmp;

	tmp = ft_llist_new(NULL);
	ft_llist_add_cmp(tmp, lst->cmp);
	ft_llist_iterparam(lst, tmp, merging);
	free_elem(lst->datas);
	lst->datas = tmp->datas;
	tmp->datas = NULL;
	ft_llist_free(&tmp);
}
