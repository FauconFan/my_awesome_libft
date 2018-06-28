/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:53:00 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/29 18:59:50 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		display(void *s)
{
	ft_printf("%s\n", s);
}

void		del(void *s)
{
	free(s);
}

void		*mem(void *s)
{
	return ((void *)ft_strdup(s));
}

int			main(void)
{
	t_list		*head;

	head = ft_lstnew("coucou", mem);
	ft_lstaddback(&head, "allo", mem);
	ft_lstaddfront(&head, "ne nous regarde pas", mem);
	ft_printf("size %d\n", ft_lstsize(head));
	ft_lstiter(head, display);
	ft_lstfreeall(&head, del);
	ft_printf("size %d\n", ft_lstsize(head));
	return (0);
}
