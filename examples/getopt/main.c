/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 12:12:00 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/13 10:28:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_arg_config			g_config_args[] = {
	{'s', NULL, "Short option", "Short called", CLI_BOOL, {FALSE}},
	{0, "long", "Long option", "Long called", CLI_BOOL, {FALSE}},
	{'m', "miscellaneous", "Short and Long option", "Short and Long called", CLI_BOOL, {FALSE}},
};

t_cli_config			g_config_cli = {
	"Cli sample",
	sizeof(g_config_args) / sizeof(g_config_args[0]),
	g_config_args,
};

t_cmd_config_n			g_config_cmd_n2[] = {
	{"Abracadra", NULL, CMD_CLI, {&g_config_cli}},
	{"Baba", NULL, CMD_CLI, {&g_config_cli}},
	{"Casse", NULL, CMD_CLI, {&g_config_cli}},
};

t_cmd_config_n			g_config_cmd_n[] = {
	{"toto", "Totouette", CMD_NODE, { .cmds = {3, g_config_cmd_n2}}},
	{"tata", "Totouette", CMD_NODE, { .cmds = {3, g_config_cmd_n2}}},
	{"tutu", "Totouette", CMD_NODE, { .cmds = {3, g_config_cmd_n2}}},
};

t_cmd_config			g_config_cmd = {
	"Sample",
	sizeof(g_config_cmd_n) / sizeof(g_config_cmd_n[0]),
	g_config_cmd_n,
};

int						main(int argc, char **argv)
{
	t_cmd_parser				*cmd_p;
	t_opt_error					err;

	cmd_p = ft_getopt_cmd(&g_config_cmd, &argc, &argv, &err);
	if (has_printed_help(err) == FALSE)
	{
		ft_putendl("You successfully called the following commands");
		ft_stab_iter(cmd_p->list_commands, (void (*)(char *))ft_putendl);
		ft_printf("short %d\n", ft_cli_getb(cmd_p->parser, "Short called"));
		ft_printf("long %d\n", ft_cli_getb(cmd_p->parser, "Long called"));
		ft_printf("short long %d\n", ft_cli_getb(cmd_p->parser, "Short and Long called"));
	}
	ft_free_cmd_parser(&cmd_p);
	return 0;
}
