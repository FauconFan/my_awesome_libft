/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:53:07 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 11:07:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_llist_find(t_llist *lst, t_bool (*f)(void *content))
{
	t_llist_elem	*actu;

	actu = lst->datas;
	while (actu)
	{
		if (f(actu->content))
			return (actu->content);
		actu = actu->next;
	}
	return (NULL);
}
