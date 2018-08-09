/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:51:30 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 15:35:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_llist_pop(t_llist *lst)
{
	t_llist_elem	*head;

	if (lst->datas == NULL)
		return ;
	head = lst->datas->next;
	(lst->free)(lst->datas->content);
	free(lst->datas);
	lst->datas = head;
	lst->len = lst->len - 1;
}
