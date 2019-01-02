/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:44:02 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/02 15:24:07 by jpriou           ###   ########.fr       */
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

/*
**	Config typedefs
*/

typedef enum				e_arg_type
{
	CLI_BOOL,
	CLI_STRING,
	CLI_ARRAY,
}							t_arg_type;

typedef enum				e_cmd_type
{
	CMD_CLI,
	CMD_NODE,
}							t_cmd_type;

union						u_arg_config
{
	t_bool					bool_val;
	char					*str_val;
};

typedef struct				s_arg_config
{
	char					single;
	char					*multi;
	char					*help;
	char					*tag;
	t_arg_type				arg_type;
	union u_arg_config		val;
}							t_arg_config;

typedef struct				s_cli_config
{
	char					*help;
	size_t					len;
	t_arg_config			args[];
}							t_cli_config;

typedef struct 				s_cmd_config_n t_cmd_config_n;

typedef struct				s_cmd_config_n2
{
	size_t					len;
	t_cmd_config_n			*sub_cmds;
}							t_cmd_config_n2;

union						u_cmd_config
{
	t_cli_config			*cli_config;
	t_cmd_config_n2			cmds;
};

typedef struct				s_cmd_config_n
{
	char					*cmd;
	char					*help;
	t_cmd_type				cmd_type;
	union u_cmd_config		u;
}							t_cmd_config_n;

typedef struct				s_cmd_config
{
	char					*help;
	size_t					nb_cmds;
	t_cmd_config_n			cmds[];
}							t_cmd_config;

#endif
