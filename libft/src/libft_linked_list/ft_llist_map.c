/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_lstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:29:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 17:48:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist					*ft_llist_map(t_llist *lst,
										void *(*f)(void *content),
										void (*free_f)(void *elem),
										int (*cmp_f)(void *d1, void *d2))
{
	t_llist			*res;
	t_llist_elem	**actu;
	t_llist_elem	*actu_lst;

	if (lst == NULL)
		return NULL;
	res = ft_llist_new(free_f, cmp_f);
	if (res == NULL)
		return NULL;
	actu = &(res->datas);
	actu_lst = lst->datas;
	while (actu_lst)
	{
		*actu = f(actu_lst);
		actu_lst = actu_lst->next;
		actu = &((*actu)->next);
	}
	return res;
}
