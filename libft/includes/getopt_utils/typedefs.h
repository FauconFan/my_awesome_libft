/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:44:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 16:18:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETOPT_TYPEDEFS_H
#define GETOPT_TYPEDEFS_H

typedef struct				s_cli_builder_parser
{
	t_llist					*short_opts;
	t_llist					*long_opts;
	t_llist					*args;
	char					*argv0;
	char					*helper;
	t_llist					*helps;
}							t_cli_builder_parser;

typedef struct				s_cli_parser
{
	int						argc;
	char					**argv;
	t_llist					*list_bool;
	t_llist					*list_string;
	t_llist					*list_array;
}							t_cli_parser;

typedef struct				s_cmd_builder_parser
{
	t_llist					*cmd_nodes;
	int						argc;
	char					**argv;
}							t_cmd_builder_parser;

typedef struct				s_cmd_builder_parser_n
{
	char					*cmd;
	t_cli_builder_parser	*cli_parser;
	t_llist					*sub_cmds;
}							t_cmd_builder_parser_n;

typedef struct				s_cmd_parser
{
	char					**list_commands;
	t_cli_parser			*parser;
}							t_cmd_parser;

typedef enum				e_opt_error
{
	OK,
	NOT_USED_WELL,
	DASH_EMPTY,
	UNKNOWN_OPTION,
	INTERNAL_ERROR,
	NO_NEXT_ARGUMENT_ALLOWED,
	NO_NEXT_ARGUMENT_GIVEN,
	COMMAND_NOT_FOUND,
	HELP_CALLED
}							t_opt_error;

#endif
