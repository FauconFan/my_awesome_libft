/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:02:44 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/09 13:35:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_free(t_llist **head)
{
	t_llist_elem	*tmp;
	t_llist_elem	*actu;

	if (head == NULL || *head == NULL)
		return ;
	tmp = (*head)->datas;
	while (tmp)
	{
		actu = tmp;
		if ((*head)->free != NULL)
			((*head)->free)(tmp->content);
		tmp = tmp->next;
		free(actu);
	}
	free(*head);
	*head = NULL;
}
