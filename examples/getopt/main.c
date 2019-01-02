/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 12:12:00 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/02 15:41:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_config			g_config_cli = {
	"Cli sample", 3,
	{
		{'s', NULL, "Short option", "Short called", CLI_BOOL, {FALSE}},
		{0, "long", "Long option", "Long called", CLI_BOOL, {FALSE}},
		{'m', "miscellaneous", "Short and Long option", "Short and Long called", CLI_BOOL, {FALSE}},
	},
};

t_cmd_config_n			g_config_cmd_n[] = {
	{"Abracadra", NULL, CMD_CLI, {&g_config_cli}},
	{"Baba", NULL, CMD_CLI, {&g_config_cli}},
	{"Casse", NULL, CMD_CLI, {&g_config_cli}},
};

t_cmd_config			g_config_cmd = {
	"Sample", 3,
	{
		{"toto", "Totouette", CMD_NODE, { .cmds = {3, g_config_cmd_n}}},
		{"tata", "Totouette", CMD_NODE, { .cmds = {3, g_config_cmd_n}}},
		{"tutu", "Totouette", CMD_NODE, { .cmds = {3, g_config_cmd_n}}},
	},
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
