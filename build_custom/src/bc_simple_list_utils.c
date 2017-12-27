/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_simple_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 22:42:32 by pepe              #+#    #+#             */
/*   Updated: 2017/12/27 10:39:08 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_custom.h"

t_simple_list		*new_simple_list(char *str)
{
	t_simple_list	*new;

	if ((new = (t_simple_list *)malloc(sizeof(t_simple_list))) == 0)
		exit(1);
	new->str = bc_strdup(str);
	new->next = 0;
	return (new);
}

void				add_list_check_doublon(char *str, t_simple_list **head)
{
	t_simple_list	*new;
	t_simple_list	*actu;
	t_simple_list	*prev;

	actu = *head;
	prev = 0;
	while (actu)
	{
		if (strcmp(str, actu->str) == 0)
		{
			return ;
		}
		prev = actu;
		actu = actu->next;
	}
	new = new_simple_list(str);
	if (prev == 0)
		*head = new;
	else
		prev->next = new;
}

t_simple_list		*bc_lstiter(t_simple_list *head, char *(*treat)(char *str))
{
	t_simple_list	*new;

	new = 0;
	if (head)
	{
		if ((new = (t_simple_list *)malloc(sizeof(t_simple_list))) == 0)
			exit (1);
		new->str = treat(head->str);
		new->next = bc_lstiter(head->next, treat);
	}
	return (new);
}

int					is_in_list(t_simple_list *head, char *str)
{
	if (head == 0)
		return (0);
	if (strcmp(head->str, str) == 0)
		return (1);
	return (is_in_list(head->next, str));
}

int					size_simple_list(t_simple_list *tmp)
{
	int		res;

	if (tmp == 0)
		return (0);
	res = 1;
	while (tmp)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

void				free_simple_list(t_simple_list **head)
{
	t_simple_list	*tmp;
	t_simple_list	*tmp2;

	if (*head == 0)
		return ;
	tmp = *head;
	while (1)
	{
		tmp2 = tmp->next;
		free(tmp->str);
		free(tmp);
		tmp = tmp2;
		if (tmp == 0)
			break ;
	}
	*head = 0;
}

void				simple_display(t_simple_list *head)
{
	while (head)
	{
		printf("%s\n", head->str);
		head = head->next;
	}
}
