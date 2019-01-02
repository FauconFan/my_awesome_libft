/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:45:30 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/02 16:08:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_config			g_config_cli = {
	"With no FILE, or when FILE is -, read standard input.", 11,
	{
		{'A', "show-all", "equivalent to -vET", "A option", CLI_BOOL, {FALSE}},
		{'b', "number-nonblank", "number nonempty output lines, overrides -n", "b option", CLI_BOOL, {FALSE}},
		{'e', NULL, "equivalent to -vE", "e option", CLI_BOOL, {FALSE}},
		{'E', "show-ends", "display $ at end of each line", "E option", CLI_BOOL, {FALSE}},
		{'n', "number", "number all output lines", "n option", CLI_STRING, { .str_val = NULL}},
		{'s', "squeeze-blank", "suppress repeated empty output lines", "s option", CLI_BOOL, {FALSE}},
		{'t', NULL, "equivalent to -vT", "t option", CLI_BOOL, {FALSE}},
		{'T', "show-tabs", "display TAB characters as ^I", "T option", CLI_BOOL, {FALSE}},
		{'u', NULL, "(ignored)", "u option", CLI_BOOL, {FALSE}},
		{'v', "show-nonprinting", "use ^ and M- notation, except for LFD and TAB", "u option", CLI_BOOL, {FALSE}},
		{0, "version", "output version information and exit", "v option", CLI_BOOL, {FALSE}},
	},
};

int						main(int argc, char **argv)
{
	t_cli_parser				*cli_p;
	t_opt_error					err;
	char						*tag;

	cli_p = ft_getopt(&g_config_cli, &argc, &argv, &err);
	if (has_printed_help(err) == FALSE)
	{
		for (size_t i = 0; i < 11; i++) {
			tag = g_config_cli.args[i].tag;
			if (g_config_cli.args[i].arg_type == CLI_BOOL)
				ft_printf("%s bool %d\n", tag, ft_cli_getb(cli_p, tag));
			else
				ft_printf("%s str  %s\n", tag, ft_cli_gets(cli_p, tag));
		}
		for (int i = 0; i < cli_p->argc; i++) {
			ft_printf("arg %d => %s\n", i, cli_p->argv[i]);
		}
	}
	ft_free_cli_parser(&cli_p);
	return 0;
}
