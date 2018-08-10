/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 12:12:00 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/10 12:48:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_builder_parser	*build_static_cli_parser()
{
	t_cli_builder_parser	*pa;

	pa = ft_create_cli_builder("Cli sample");
	ft_cli_add_u(pa,
				ft_create_s_opt('s', "Short option"),
				ft_create_bool_arg("Short called", FALSE));
	ft_cli_add_u(pa,
				ft_create_l_opt("long", "Long option"),
				ft_create_bool_arg("Long called", FALSE));
	ft_cli_add_u(pa,
				ft_create_sl_opt('m', "miscellaneous", "Short and Long option"),
				ft_create_bool_arg("Short and Long called", FALSE));
	return pa;
}

t_cmd_builder_parser_n	*build_cmd(char *cmd)
{
	t_cmd_builder_parser_n	*res;
	t_cmd_builder_parser_n	*n1;
	t_cmd_builder_parser_n	*n2;
	t_cmd_builder_parser_n	*n3;
	t_cli_builder_parser	*cli_p;

	res = ft_create_cmd_builder_parser_node_cmd(cmd, "Totouette");
	cli_p = build_static_cli_parser();
	n1 = ft_create_cmd_builder_parser_node_cli("Abracadra", "AAAAAAAH", &cli_p);
	cli_p = build_static_cli_parser();
	n2 = ft_create_cmd_builder_parser_node_cli("Baba", "BBBBBBB", &cli_p);
	cli_p = build_static_cli_parser();
	n3 = ft_create_cmd_builder_parser_node_cli("Casse", "Krack", &cli_p);
	ft_add_sub_cmd(res, &n1);
	ft_add_sub_cmd(res, &n2);
	ft_add_sub_cmd(res, &n3);
	return res;
}

int						main(int argc, char **argv)
{
	t_cmd_parser				*cmd_p;
	t_cmd_builder_parser		*cmd_bd_p;
	t_opt_error					err;

	cmd_bd_p = ft_create_cmd_builder_parser(&argc, &argv, "Sample");
	ft_add_cmd_u(cmd_bd_p, build_cmd("toto"));
	ft_add_cmd_u(cmd_bd_p, build_cmd("tata"));
	ft_add_cmd_u(cmd_bd_p, build_cmd("tutu"));
	cmd_p = ft_run_cmd(&cmd_bd_p, &err);
	if (has_printed_help(err) == FALSE)
	{
		ft_putendl("You successfully called the folloing commands");
		ft_stab_iter(cmd_p->list_commands, (void (*)(char *))ft_putendl);
		ft_printf("short %d\n", ft_cli_getb(cmd_p->parser, "Short called"));
		ft_printf("long %d\n", ft_cli_getb(cmd_p->parser, "Long called"));
		ft_printf("short long %d\n", ft_cli_getb(cmd_p->parser, "Short and Long called"));
	}
	ft_free_cmd_parser(&cmd_p);
	return 0;
}
