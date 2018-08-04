/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:38:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 15:11:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddfront(t_list **head, void *content)
{
	t_list	*tmp;

	if (head == 0)
		return ;
	tmp = *head;
	*head = ft_lstnew(content);
	(*head)->next = tmp;
}
