/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:53:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 15:23:09 by jpriou           ###   ########.fr       */
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

int			main(void)
{
	t_list		*head;

	head = ft_lstnew(ft_strdup("coucou"));
	ft_lstaddback(&head, ft_strdup("allo"));
	ft_lstaddfront(&head, ft_strdup("ne nous regarde pas"));
	ft_printf("size %d\n", ft_lstsize(head));
	ft_lstiter(head, display);
	ft_lstfreeall(&head, del);
	ft_printf("size %d\n", ft_lstsize(head));
	return (0);
}
