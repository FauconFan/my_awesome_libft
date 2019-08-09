/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder_parser_node2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:52:11 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 17:53:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						ft_free_cmd_builder_parser_node(
								t_cmd_builder_parser_n *build_node)
{
	ft_strdel(&(build_node->cmd));
	ft_strdel(&(build_node->helper));
	ft_free_cli_builder(build_node->cli_parser);
	ft_slist_free(&(build_node->sub_cmds));
	free(build_node);
}

void						ft_add_sub_cmd_u(
								t_cmd_builder_parser_n *p,
								t_cmd_builder_parser_n *n)
{
	ft_slist_push(p->sub_cmds, n);
}

void						ft_add_sub_cmd(
								t_cmd_builder_parser_n *p,
								t_cmd_builder_parser_n **n)
{
	ft_add_sub_cmd_u(p, *n);
	*n = NULL;
}
