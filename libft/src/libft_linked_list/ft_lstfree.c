/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:02:44 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/10 15:07:47 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfreeall(t_list **head, void (*free_elem)(void *content))
{
	t_list	*tmp;
	t_list	*actu;

	if (head == 0)
		return ;
	tmp = *head;
	while (tmp)
	{
		actu = tmp;
		free_elem(tmp->content);
		tmp = tmp->next;
		free(actu);
	}
	*head = 0;
}
