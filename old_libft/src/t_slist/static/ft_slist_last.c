/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:10:03 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 18:05:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_slist_last(t_slist *lst)
{
	t_slist_elem	*actu;

	actu = lst->head;
	if (actu == NULL)
		return (NULL);
	while (actu->next)
		actu = actu->next;
	return (actu->content);
}
