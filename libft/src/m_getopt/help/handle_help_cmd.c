/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_help_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:17:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 13:09:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_properly(void *elem, void *param)
{
	t_cmd_builder_parser_n	*n;
	t_slist					*lst;
	char					*rep;
	char					*helper;

	n = (t_cmd_builder_parser_n *)elem;
	lst = (t_slist *)param;
	helper = build_helper_properly(n->helper, 32, 50);
	ft_sprintf(&rep, "   %-27s  %s", n->cmd, helper);
	ft_slist_push(lst, rep);
	ft_strdel(&helper);
}

t_slist		*build_help_command(t_slist *cmds)
{
	t_slist		*res;

	res = ft_slist_new(free);
	ft_slist_add_cmp(res, MAKE_CMP_PTR(ft_strcmp));
	ft_slist_iterparam(cmds, res, add_properly);
	ft_slist_sort(res);
	return res;
}

void		handle_help_cmd(
					char *argv0,
					t_slist **lst_node,
					t_opt_error *e,
					char *helper)
{
	char	*error_mean;
	t_slist	*cmds;

	cmds = build_help_command(*lst_node);
	error_mean = NULL;
	if (e)
		error_mean = ft_cli_getstr_rc(*e);
	ft_printf("Usage: %s [CMDS...] [OPTIONS...] [ARGS...]\n\n", argv0);
	ft_printf("%s\n\n", helper);
	if (error_mean)
		ft_printf("%s\n\n", error_mean);
	ft_putendl("Commands:");
	ft_slist_iter(cmds, (void (*)(void *))ft_putendl);
	ft_slist_free(&cmds);
}
