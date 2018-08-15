/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_tovtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 13:16:15 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/15 13:27:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_slist_tovtab(t_slist **lst)
{
	void			**res;
	t_slist_elem	*next;
	t_slist_elem	*elem;
	size_t			i;

	res = ft_vtab_new(ft_slist_size(*lst), NULL, 0);
	i = 0;
	elem = (*lst)->head;
	while (elem)
	{
		next = elem->next;
		res[i] = elem->content;
		free(elem);
		elem = next;
		i++;
	}
	(*lst)->head = NULL;
	ft_slist_free(lst);
	return (res);
}
