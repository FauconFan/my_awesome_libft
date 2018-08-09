/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:12:52 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 15:48:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*get_i(t_llist_elem *elem, size_t i)
{
	if (elem == NULL)
		return NULL;
	if (i == 0)
		return elem->content;
	return get_i(elem->next, i - 1);
}

void			*ft_llist_get(t_llist *lst, size_t i)
{
	if (i >= lst->len)
		return NULL;
	return get_i(lst->datas, i);
}
