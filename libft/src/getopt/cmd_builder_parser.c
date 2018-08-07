/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:59:54 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 14:27:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd_builder_parser	*ft_create_cmd_builder_parser(int *argc, char ***argv)
{
	t_cmd_builder_parser	*res;

	if (*argc <= 0)
		return NULL;
	ft_memcheck(
		(res = (t_cmd_builder_parser *)malloc(sizeof(t_cmd_builder_parser))));
	res->cmd_nodes = ft_llist_new(ft_free_cmd_builder_parser_node, NULL);
	res->argc = *argc;
	res->argv = *argv;
	*argc = -1;
	*argv = NULL;
	return res;
}

void					ft_free_cmd_builder_parser(t_cmd_builder_parser **pa)
{
	t_cmd_builder_parser	*p;

	p = *pa;
	ft_llist_free(&(p->cmd_nodes));
	free(p);
	*pa = NULL;
}

void					ft_add_cmd(
							t_cmd_builder_parser *p,
							t_cmd_builder_parser_n **n)
{
	ft_llist_addfront(p->cmd_nodes, *n);
	*n = NULL;
}
