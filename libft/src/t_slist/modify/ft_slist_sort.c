/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:32:13 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:43:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		merging(void *elem, void *lst_ptr)
{
	t_slist		*lst;

	lst = (t_slist *)lst_ptr;
	ft_slist_merge_one(lst, elem);
}

static void		free_elem(t_slist_elem *head)
{
	if (head != NULL)
	{
		free_elem(head->next);
		free(head);
	}
}

void			ft_slist_sort(t_slist *lst)
{
	t_slist			*tmp;

	tmp = ft_slist_new(NULL);
	ft_slist_add_cmp(tmp, lst->cmp);
	ft_slist_iterparam(lst, tmp, merging);
	free_elem(lst->head);
	lst->head = tmp->head;
	tmp->head = NULL;
	ft_slist_free(&tmp);
}
