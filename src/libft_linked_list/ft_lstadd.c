/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:24:51 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 15:46:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddfront(t_list **head, void *content, void *(*cpy)(void *data))
{
	t_list	*tmp;

	if (head == 0)
		return ;
	tmp = *head;
	*head = ft_lstnew(content, cpy);
	(*head)->next = tmp;
}

void	ft_lstaddfront_nocpy(t_list **head, void *content)
{
	t_list	*tmp;

	if (head == 0)
		return ;
	tmp = *head;
	*head = ft_lstnew_nocpy(content);
	(*head)->next = tmp;
}

void	ft_lstaddback(t_list **head, void *content, void *(*cpy)(void *data))
{
	t_list	*tmp;
	t_list	*actu;

	if (head == 0)
		return ;
	tmp = ft_lstnew(content, cpy);
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

void	ft_lstaddback_nocpy(t_list **head, void *content)
{
	t_list	*tmp;
	t_list	*actu;

	if (head == 0)
		return ;
	tmp = ft_lstnew_nocpy(content);
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
