/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_builder_parser_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:13:48 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 09:17:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_cmd_builder_parser_n	*init_builder(
									char *str,
									char *helper,
									t_cli_builder_parser *cli_parser,
									t_slist *sub_cmds)
{
	t_cmd_builder_parser_n	*res;

	ft_memcheck((res = (t_cmd_builder_parser_n *)
						malloc(sizeof(t_cmd_builder_parser_n))));
	res->cmd = ft_strdup(str);
	res->helper = ft_strdup(helper);
	res->cli_parser = cli_parser;
	res->sub_cmds = sub_cmds;
	return (res);
}

t_cmd_builder_parser_n			*ft_create_help_sub_cmd(void)
{
	return (init_builder(HELP_CMD, HELP_MSG, NULL, NULL));
}

t_cmd_builder_parser_n			*ft_create_cmd_builder_parser_node_cmd(
									char *cmd,
									char *helper)
{
	t_cmd_builder_parser_n	*res;

	res = init_builder(cmd, helper, NULL,
		ft_slist_new(MAKE_FREE_PTR(ft_free_cmd_builder_parser_node)));
	ft_slist_push(res->sub_cmds, ft_create_help_sub_cmd());
	return (res);
}

t_cmd_builder_parser_n			*ft_create_cmd_builder_parser_node_cli_w_help(
									char *cmd,
									char *help,
									t_cli_builder_parser **builder_cli)
{
	t_cmd_builder_parser_n	*res;

	res = init_builder(cmd, help, *builder_cli, NULL);
	*builder_cli = NULL;
	return (res);
}

t_cmd_builder_parser_n			*ft_create_cmd_builder_parser_node_cli(
									char *cmd,
									t_cli_builder_parser **builder_cli)
{
	return (ft_create_cmd_builder_parser_node_cli_w_help(
				cmd, (*builder_cli)->helper, builder_cli));
}
