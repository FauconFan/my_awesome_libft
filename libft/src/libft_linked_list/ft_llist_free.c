/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:02:44 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/04 16:53:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_free(t_llist **head)
{
	t_llist_elem	*tmp;
	t_llist_elem	*actu;

	if (head == NULL)
		return ;
	tmp = (*head)->datas;
	while (tmp)
	{
		actu = tmp;
		((*head)->free)(tmp->content);
		tmp = tmp->next;
		free(actu);
	}
	*head = NULL;
}
