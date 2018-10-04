/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder_parser_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:13:48 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 17:53:26 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd_builder_parser_n		*ft_create_help_sub_cmd(void)
{
	t_cmd_builder_parser_n	*res;

	ft_memcheck((res = (t_cmd_builder_parser_n *)
						malloc(sizeof(t_cmd_builder_parser_n))));
	res->cmd = ft_strdup(HELP_CMD);
	res->helper = ft_strdup(HELP_MSG);
	res->cli_parser = NULL;
	res->sub_cmds = NULL;
	return (res);
}

t_cmd_builder_parser_n		*ft_create_cmd_builder_parser_node_cmd(
								char *cmd,
								char *helper)
{
	t_cmd_builder_parser_n	*res;

	ft_memcheck((res = (t_cmd_builder_parser_n *)
						malloc(sizeof(t_cmd_builder_parser_n))));
	res->cmd = ft_strdup(cmd);
	res->helper = ft_strdup(helper);
	res->cli_parser = NULL;
	res->sub_cmds =
			ft_slist_new(MAKE_FREE_PTR(ft_free_cmd_builder_parser_node));
	ft_slist_push(res->sub_cmds, ft_create_help_sub_cmd());
	return (res);
}

t_cmd_builder_parser_n		*ft_create_cmd_builder_parser_node_cli(
								char *cmd,
								t_cli_builder_parser **builder_cli)
{
	t_cmd_builder_parser_n	*res;

	ft_memcheck((res = (t_cmd_builder_parser_n *)
						malloc(sizeof(t_cmd_builder_parser_n))));
	res->cmd = ft_strdup(cmd);
	res->helper = ft_strdup((*builder_cli)->helper);
	res->cli_parser = *builder_cli;
	res->sub_cmds = NULL;
	*builder_cli = NULL;
	return (res);
}
