/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_help_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:17:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 17:10:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	display_f(void *elem)
{
	t_cmd_builder_parser_n	*n1;

	n1 = (t_cmd_builder_parser_n *)elem;
	ft_printf("   %s\n", n1->cmd);
}

static int	cmp_f(void *d1, void *d2)
{
	t_cmd_builder_parser_n	*n1;
	t_cmd_builder_parser_n	*n2;

	n1 = (t_cmd_builder_parser_n *)d1;
	n2 = (t_cmd_builder_parser_n *)d2;
	return ft_strcmp(n1->cmd, n2->cmd);
}

void		handle_help_cmd(t_llist **lst_node, t_opt_error *e)
{
	(void)e;
	ft_llist_sort(lst_node, cmp_f);
	ft_printf("Usage: Some Header Stuff\n\n");
	ft_printf("Some helper\n\n");
	ft_printf("Some error stuff if there is.\n\n");
	ft_putendl("Commands:");
	ft_llist_iter(*lst_node, display_f);
}
