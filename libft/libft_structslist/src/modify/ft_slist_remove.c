/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:42:32 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 07:42:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"

void			ft_slist_remove(t_slist *lst, size_t i)
{
	t_slist_elem	*prev;
	t_slist_elem	*next_next;

	if (i >= lst->len)
		return ;
	if (i == 0)
	{
		ft_slist_pop(lst);
		return ;
	}
	lst->len = lst->len - 1;
	prev = lst->head;
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
