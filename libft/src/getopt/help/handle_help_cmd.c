/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_help_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:17:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:06:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_properly(void *elem, void *param)
{
	t_cmd_builder_parser_n	*n;
	t_llist					*lst;
	char					*rep;

	n = (t_cmd_builder_parser_n *)elem;
	lst = (t_llist *)param;
	ft_sprintf(&rep, "   %-27s  %s", n->cmd, n->helper);
	ft_llist_addfront(lst, rep);
}

t_llist		*build_help_command(t_llist *cmds)
{
	t_llist		*res;

	res = ft_llist_new(free);
	ft_llist_add_cmp(res, MAKE_CMP_PTR(ft_strcmp));
	ft_llist_iterparam(cmds, res, add_properly);
	ft_llist_sort(res);
	return res;
}

void		handle_help_cmd(
					char *argv0,
					t_llist **lst_node,
					t_opt_error *e,
					char *helper)
{
	char	*error_mean;
	t_llist	*cmds;

	cmds = build_help_command(*lst_node);
	error_mean = NULL;
	if (e)
		error_mean = ft_cli_getstr_rc(*e);
	ft_printf("Usage: %s [CMDS...] [OPTIONS...] [ARGS...]\n\n", argv0);
	ft_printf("%s\n\n", helper);
	if (error_mean)
		ft_printf("%s\n\n", error_mean);
	ft_putendl("Commands:");
	ft_llist_iter(cmds, (void (*)(void *))ft_putendl);
	ft_llist_free(&cmds);
}
