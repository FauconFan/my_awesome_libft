/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:32:13 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 16:48:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *elem, void *lst_ptr, void *ptr_cmp)
{
	t_llist		*lst;
	int			(*cmp_f)(void *d1, void *d2);

	lst = (t_llist *)lst_ptr;
	cmp_f = (int (*)(void *, void *))ptr_cmp;
	ft_llist_merge_one(lst, elem, cmp_f);
}

static void		free_elem(t_llist_elem *head)
{
	if (head != NULL)
	{
		free_elem(head->next);
		free(head);
	}
}

void			ft_llist_sort(t_llist **lst, int (*cmp_f)(void *d1, void *d2))
{
	t_llist			*res;

	res = ft_llist_new((*lst)->free, (*lst)->cpy);
	ft_llist_iterparam2(*lst, res, cmp_f, f);
	free_elem((*lst)->datas);
	free(*lst);
	*lst = res;
}
