/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:37:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 15:33:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd_builder_parser_n	*build_run_cmd(t_cmd_builder_parser *p)
{
	t_cli_builder_parser	*bd_cli;

	bd_cli = ft_create_cli_builder(*(p->argv), "Run a command in a new container");
	ft_cli_add_u(bd_cli,
		ft_create_l_opt("add-host", "Add a custom host-to-IP mapping (host:ip)"),
		ft_create_array_arg("add-host-target"));
	ft_cli_add_u(bd_cli,
		ft_create_sl_opt('a', "attach", "Attach to STDIN, STDOUT or STDERR"),
		ft_create_array_arg("attach-target"));
	return ft_create_cmd_builder_parser_node_cli("run", &bd_cli);
}

int main(int argc, char **argv) {
	t_cmd_builder_parser	*cmd_bd_parser;
	t_cmd_builder_parser_n	*run_cmd;
	t_cmd_parser			*res_parser;
	t_opt_error				err;

	cmd_bd_parser = ft_create_cmd_builder_parser(&argc, &argv);
	run_cmd = build_run_cmd(cmd_bd_parser);
	ft_add_cmd(cmd_bd_parser, &run_cmd);
	res_parser = ft_run_cmd(cmd_bd_parser, &err);
	ft_free_cmd_builder_parser(&cmd_bd_parser);
	ft_free_cmd_parser(&res_parser);
	return 0;
}
