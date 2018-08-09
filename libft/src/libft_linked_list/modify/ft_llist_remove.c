/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:42:32 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:51:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_llist_remove(t_llist *lst, size_t i)
{
	t_llist_elem	*prev;
	t_llist_elem	*next_next;

	if (i >= lst->len)
		return ;
	if (i == 0)
	{
		ft_llist_pop(lst);
		return ;
	}
	lst->len = lst->len - 1;
	prev = lst->datas;
	i--;
	while (i != 0)
	{
		prev = prev->next;
	}
	next_next = prev->next->next;
	(lst->free)(prev->next->content);
	free(prev->next);
	prev->next = next_next;
}
