/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:53:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/04 18:10:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		display(void *s)
{
	ft_printf("%s ", s);
}

void		del(void *s)
{
	free(s);
}

int			main(void)
{
	t_llist		*head;

	head = ft_llist_new(del, NULL);
	ft_llist_addfront(head, ft_strdup("2"));
	ft_llist_addback(head, ft_strdup("3"));
	ft_llist_addfront(head, ft_strdup("1"));
	ft_printf("size %d\n", ft_llist_size(head));
	ft_llist_iter(head, display);
	ft_putchar('\n');
	ft_llist_free(&head);
	ft_printf("size %d\n", ft_llist_size(head));
	return (0);
}
