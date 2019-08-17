/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:51:30 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:42:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"

void			ft_slist_pop(t_slist *lst)
{
	t_slist_elem	*head;

	if (lst->head == NULL)
		return ;
	head = lst->head->next;
	(lst->free)(lst->head->content);
	free(lst->head);
	lst->head = head;
	lst->len = lst->len - 1;
}
