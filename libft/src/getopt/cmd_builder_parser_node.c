/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder_parser_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:13:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 15:31:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd_builder_parser_n		*ft_create_cmd_builder_parser_node_cmd(char *cmd)
{
	t_cmd_builder_parser_n	*res;

	ft_memcheck((res = (t_cmd_builder_parser_n *)
						malloc(sizeof(t_cmd_builder_parser_n))));
	res->cmd = ft_strdup(cmd);
	res->cli_parser = NULL;
	res->sub_cmds = ft_llist_new(ft_free_cmd_builder_parser_node, NULL);
	return res;
}

t_cmd_builder_parser_n		*ft_create_cmd_builder_parser_node_cli(
								char *cmd,
								t_cli_builder_parser **builder_cli)
{
	t_cmd_builder_parser_n	*res;

	ft_memcheck((res = (t_cmd_builder_parser_n *)
						malloc(sizeof(t_cmd_builder_parser_n))));
	res->cmd = ft_strdup(cmd);
	res->cli_parser = *builder_cli;
	res->sub_cmds = NULL;
	*builder_cli = NULL;
	return res;
}

void						ft_free_cmd_builder_parser_node(void *n)
{
	t_cmd_builder_parser_n	*build_node;

	build_node = (t_cmd_builder_parser_n *)n;
	free(build_node->cmd);
	ft_free_cli_builder(build_node->cli_parser);
	ft_llist_free(&(build_node->sub_cmds));
	free(build_node);
}

void						ft_add_sub_cmd(
								t_cmd_builder_parser_n *p,
								t_cmd_builder_parser_n **n)
{
	ft_llist_addfront(p->sub_cmds, *n);
	*n = NULL;
}
