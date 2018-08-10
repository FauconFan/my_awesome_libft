/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:59:54 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:08:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd_builder_parser	*ft_create_cmd_builder_parser(
								int *argc,
								char ***argv,
								char *helper)
{
	t_cmd_builder_parser	*res;

	if (*argc <= 0)
		return NULL;
	ft_memcheck(
		(res = (t_cmd_builder_parser *)malloc(sizeof(t_cmd_builder_parser))));
	res->cmd_nodes = ft_slist_new(MAKE_FREE_PTR(ft_free_cmd_builder_parser_node));
	res->helper = ft_strdup(helper);
	res->argc = *argc;
	res->argv = *argv;
	res->argv0 = NULL;
	*argc = -1;
	*argv = NULL;
	ft_slist_addfront(res->cmd_nodes, ft_create_help_sub_cmd());
	return res;
}

void					ft_free_cmd_builder_parser(t_cmd_builder_parser **pa)
{
	t_cmd_builder_parser	*p;

	p = *pa;
	ft_strdel(&(p->helper));
	ft_slist_free(&(p->cmd_nodes));
	ft_strdel(&(p->argv0));
	free(p);
	*pa = NULL;
}

void					ft_add_cmd_u(
							t_cmd_builder_parser *p,
							t_cmd_builder_parser_n *n)
{
	ft_slist_addfront(p->cmd_nodes, n);
}

void					ft_add_cmd(
							t_cmd_builder_parser *p,
							t_cmd_builder_parser_n **n)
{
	ft_add_cmd_u(p, *n);
	*n = NULL;
}
