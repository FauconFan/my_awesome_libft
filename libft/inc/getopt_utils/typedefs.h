/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:44:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 17:51:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETOPT_TYPEDEFS_H
# define GETOPT_TYPEDEFS_H

# define HELP_CMD			"help"
# define HELP_MSG			"Print this message and exit"

# define U_ERR	"User error: "
# define I_ERR	"Internal error: "
# define D_ERR	"Developper error: "

typedef struct				s_cli_builder_parser
{
	t_slist					*short_opts;
	t_slist					*long_opts;
	t_slist					*args;
	char					*helper;
	t_slist					*helps;
}							t_cli_builder_parser;

typedef struct				s_cli_parser
{
	int						argc;
	char					**argv;
	t_slist					*list_bool;
	t_slist					*list_string;
	t_slist					*list_array;
}							t_cli_parser;

typedef struct				s_cmd_builder_parser
{
	t_slist					*cmd_nodes;
	char					*helper;
	int						argc;
	char					**argv;
	char					*argv0;
}							t_cmd_builder_parser;

typedef struct				s_cmd_builder_parser_n
{
	char					*cmd;
	char					*helper;
	t_cli_builder_parser	*cli_parser;
	t_slist					*sub_cmds;
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
