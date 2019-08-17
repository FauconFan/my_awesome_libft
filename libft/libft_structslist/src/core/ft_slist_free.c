/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfa <fauconfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:02:44 by fauconfa          #+#    #+#             */
/*   Updated: 2018/08/10 07:42:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_structslist.h"

void	ft_slist_free(t_slist **head)
{
	t_slist_elem	*tmp;
	t_slist_elem	*actu;

	if (head == NULL || *head == NULL)
		return ;
	tmp = (*head)->head;
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
