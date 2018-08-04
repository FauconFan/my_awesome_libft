/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:39:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 17:03:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_addback(t_llist *head, void *content)
{
	t_llist_elem	*tmp;
	t_llist_elem	*actu;

	if (head == 0)
		return ;
	tmp = ft_llist_elem_new(content);
	if (head->datas == 0)
		head->datas = tmp;
	else
	{
		actu = head->datas;
		while (actu->next)
			actu = actu->next;
		actu->next = tmp;
	}
}
