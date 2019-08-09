/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_addfront.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:38:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 11:30:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_slist_addfront(t_slist *head, void *content, t_bool do_cpy)
{
	t_slist_elem	*tmp;

	if (head == 0)
		return ;
	head->len = head->len + 1;
	tmp = head->head;
	if (do_cpy)
		head->head = ft_slist_elem_new((head->cpy)(content));
	else
		head->head = ft_slist_elem_new(content);
	head->head->next = tmp;
}
