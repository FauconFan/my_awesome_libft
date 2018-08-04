/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_addfront.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:38:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 17:00:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_addfront(t_llist *head, void *content)
{
	t_llist_elem	*tmp;

	if (head == 0)
		return ;
	tmp = head->datas;
	head->datas = ft_llist_elem_new(content);
	head->datas->next = tmp;
}
