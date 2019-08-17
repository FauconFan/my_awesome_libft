/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:29:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 18:06:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"

t_slist					*ft_slist_map(t_slist *lst,
										void *(*f)(void *content),
										void (*free_f)(void *elem))
{
	t_slist			*res;
	t_slist_elem	**actu;
	t_slist_elem	*actu_lst;

	if (lst == NULL)
		return (NULL);
	res = ft_slist_new(free_f);
	if (res == NULL)
		return (NULL);
	actu = &(res->head);
	actu_lst = lst->head;
	while (actu_lst)
	{
		*actu = ft_slist_elem_new(f(actu_lst->content));
		actu = &((*actu)->next);
		actu_lst = actu_lst->next;
	}
	return (res);
}
