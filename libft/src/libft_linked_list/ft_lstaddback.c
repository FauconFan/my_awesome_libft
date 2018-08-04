/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:39:35 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 15:11:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **head, void *content)
{
	t_list	*tmp;
	t_list	*actu;

	if (head == 0)
		return ;
	tmp = ft_lstnew(content);
	if (*head == 0)
		*head = tmp;
	else
	{
		actu = *head;
		while (actu->next)
			actu = actu->next;
		actu->next = tmp;
	}
}
