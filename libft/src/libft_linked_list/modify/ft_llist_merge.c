/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:12:04 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:10:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *content, void *lst_ptr)
{
	t_llist		*lst;

	lst = (t_llist *)lst_ptr;
	ft_llist_merge_one(lst, lst->cpy(content));
}

t_bool			ft_llist_merge(
					t_llist *lst1,
					t_llist	*lst2)
{
	if (lst1->cmp == NULL
		|| lst1->cmp != lst2->cmp
		|| lst1->cpy == NULL
		|| lst1->cpy != lst2->cpy)
		return FALSE;
	ft_llist_iterparam(lst2, lst1, f);
	return TRUE;
}
