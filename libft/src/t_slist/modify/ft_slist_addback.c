/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:39:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 11:30:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_slist_addback(t_slist *head, void *content, t_bool do_cpy)
{
	t_slist_elem	*tmp;
	t_slist_elem	*actu;

	if (head == 0)
		return ;
	head->len = head->len + 1;
	if (do_cpy)
		tmp = ft_slist_elem_new((head->cpy)(content));
	else
		tmp = ft_slist_elem_new(content);
	if (head->head == NULL)
		head->head = tmp;
	else
	{
		actu = head->head;
		while (actu->next)
			actu = actu->next;
		actu->next = tmp;
	}
}
