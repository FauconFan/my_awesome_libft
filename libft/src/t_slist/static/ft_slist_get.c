/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:12:52 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 18:05:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*get_i(t_slist_elem *elem, size_t i)
{
	if (elem == NULL)
		return (NULL);
	if (i == 0)
		return (elem->content);
	return (get_i(elem->next, i - 1));
}

void			*ft_slist_get(t_slist *lst, size_t i)
{
	if (i >= lst->len)
		return (NULL);
	return (get_i(lst->head, i));
}
