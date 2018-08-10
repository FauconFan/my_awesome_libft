/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:37:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 13:46:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define HELP_STD		"Get Opt example applied to Docker Run"
#define HELP_RUN		"Run a command in a new container"

#define OPT_ADD_HOST	"Add a custom host-to-IP mapping (host=ip)::add-host;add-host-target:array"
#define OPT_ATTACH		"Attach to STDIN, STDOUT or STDERR:a:attach;attach-target:array"
#define OPT_KIOTA		"Block IO (relative weight), between 10 and 1000, or 0 to disable (default 0)::blkio-weight;blkio-weight-target:string"
#define OPT_KIODTA		"Block IO weight (relative device weight) (default [])::blkio-weight-device;blkio-weight-device-target:array"
#define OPT_CAPADD		"Add Linux capabilities::cap-add;cap-add-target:array"
#define OPT_CAPDROP		"Drop Linux capabilities::cap-drop;cap-drop-target:array"
#define OPT_CGROUP		"Optional parent cgroup for the container::cgroup-parent;cgroup-parent-target:string"

#define OPTS			OPT_ADD_HOST "|" OPT_ATTACH "|" OPT_KIOTA "|" OPT_KIODTA "|" OPT_CAPADD "|" OPT_CAPDROP "|" OPT_CGROUP

#define RUN_CMD			"{run:(" HELP_RUN ":" OPTS ")}"

#define CONFIG_OPT		HELP_STD ":" RUN_CMD

t_cmd_builder_parser_n	*build_run_cmd()
{
	t_cli_builder_parser	*bd_cli;

	bd_cli = ft_create_cli_builder("Run a command in a new container");
	ft_cli_add_u(bd_cli,
		ft_create_l_opt("add-host", "Add a custom host-to-IP mapping (host=ip)"),
		ft_create_array_arg("add-host-target"));
	ft_cli_add_u(bd_cli,
		ft_create_sl_opt('a', "attach", "Attach to STDIN, STDOUT or STDERR"),
		ft_create_array_arg("attach-target"));
	ft_cli_add_u(bd_cli,
		ft_create_l_opt("blkio-weight", "Block IO (relative weight), between 10 and 1000, or 0 to disable (default 0)"),
		ft_create_string_arg("blkio-weight-target", NULL));
	ft_cli_add_u(bd_cli,
		ft_create_l_opt("blkio-weight-device", "Block IO weight (relative device weight) (default [])"),
		ft_create_array_arg("blkio-weight-device-target"));
	ft_cli_add_u(bd_cli,
		ft_create_l_opt("cap-add", "Add Linux capabilities"),
		ft_create_array_arg("cap-add-target"));
	ft_cli_add_u(bd_cli,
		ft_create_l_opt("cap-drop", "Drop Linux capabilities"),
		ft_create_array_arg("cad-drop-target"));
	ft_cli_add_u(bd_cli,
		ft_create_l_opt("cgroup-parent", "Optional parent cgroup for the container"),
		ft_create_string_arg("cgroup-parent-target", NULL));
	return ft_create_cmd_builder_parser_node_cli(
						"run",
						&bd_cli);
}

void	do_main(int *argc, char ***argv)
{
	t_cmd_builder_parser	*cmd_bd_parser;
	t_cmd_builder_parser_n	*run_cmd;
	t_cmd_parser			*res_parser;
	t_opt_error				err;

	cmd_bd_parser = ft_create_cmd_builder_parser(argc, argv,
			"Get Opt example applied to Docker Run");
	run_cmd = build_run_cmd();
	ft_add_cmd(cmd_bd_parser, &run_cmd);
	res_parser = ft_run_cmd(&cmd_bd_parser, &err);
	if (has_printed_help(err) == FALSE)
	{
		ft_putendl("Use this program with --help, to show helper");
	}
	ft_free_cmd_parser(&res_parser);
}

int main(int argc, char **argv) {
	// do_main(&argc, &argv);
	t_cmd_parser	*cmd;
	t_opt_error		err;

	cmd = ft_getopt(CONFIG_OPT, &argc, &argv, &err);
	(void)cmd;
	(void)err;
	// ft_free_cmd_parser(&cmd);
	return 0;
}
