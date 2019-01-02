/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 15:34:36 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/02 15:40:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				build_cli_arguments(
							t_arg_config *arg_config,
							t_cli_opt **opt,
							t_cli_arg **arg)
{
	if (arg_config->single != 0 && arg_config->multi != NULL)
		*opt = ft_create_sl_opt(arg_config->single, arg_config->multi, arg_config->help);
	else if (arg_config->single != 0)
		*opt = ft_create_s_opt(arg_config->single, arg_config->help);
	else
		*opt = ft_create_l_opt(arg_config->multi, arg_config->help);
	if (arg_config->arg_type == CLI_BOOL)
		*arg = ft_create_bool_arg(arg_config->tag, arg_config->val.bool_val);
	else if (arg_config->arg_type == CLI_STRING)
		*arg = ft_create_string_arg(arg_config->tag, arg_config->val.str_val);
	else
		*arg = ft_create_array_arg(arg_config->tag);
}

t_cli_builder_parser 	*build_cli_parser(t_cli_config *cli_config)
{
	t_cli_builder_parser	*res;
	size_t					index;
	t_cli_opt				*opt;
	t_cli_arg				*arg;

	res = ft_create_cli_builder(cli_config->help);
	index = 0;
	while (index < cli_config->len)
	{
		build_cli_arguments(cli_config->args + index, &opt, &arg);
		ft_cli_add_u(res, opt, arg);
		++index;
	}
	return (res);
}

static t_cmd_builder_parser_n *
build_cmd_parser_n_cli(t_cmd_config_n *config)
{
	t_cli_config			*cli_config;
	t_cmd_builder_parser_n	*res;
	t_cli_builder_parser	*cli_parser;

	cli_config = config->u.cli_config;
	cli_parser = build_cli_parser(cli_config);
	if (config->help == NULL)
		res = ft_create_cmd_builder_parser_node_cli(config->cmd, &cli_parser);
	else
		res = ft_create_cmd_builder_parser_node_cli_w_help(config->cmd, config->help, &cli_parser);
	return (res);
}

static t_cmd_builder_parser_n *
build_cmd_parser_n(t_cmd_config_n *config)
{
	t_cmd_builder_parser_n	*res;
	t_cmd_builder_parser_n	*tmp;
	size_t					index;

	if (config->cmd_type == CMD_CLI)
		return (build_cmd_parser_n_cli(config));
	res = ft_create_cmd_builder_parser_node_cmd(config->cmd, config->help);
	index = 0;
	while (index < config->u.cmds.len)
	{
		tmp = build_cmd_parser_n(config->u.cmds.sub_cmds + index);
		ft_add_sub_cmd(res, &tmp);
		index++;
	}
	return (res);
}

t_cmd_builder_parser *
build_cmd_parser(t_cmd_config *config, int *argc, char ***argv)
{
	t_cmd_builder_parser	*res;
	size_t					index;

	res = ft_create_cmd_builder_parser(argc, argv, config->help);
	index = 0;
	while (index < config->nb_cmds)
	{
		ft_add_cmd_u(res, build_cmd_parser_n(config->cmds + index));
		index++;
	}
	return (res);
}
