/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:10:03 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 15:49:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_llist_last(t_llist *lst)
{
	t_llist_elem	*actu;

	actu = lst->datas;
	if (actu == NULL)
		return NULL;
	while (actu->next)
		actu = actu->next;
	return actu->content;
}
