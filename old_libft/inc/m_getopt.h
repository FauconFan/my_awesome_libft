/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_getopt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:04:34 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/02 15:42:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_GETOPT_H
# define M_GETOPT_H

# include "libft.h"
# include "inc/f_tab.h"
# include "inc/t_slist.h"
# include "inc/getopt_utils/typedefs.h"
# include "inc/getopt_utils/getopt_utils.h"

t_cmd_parser			*ft_getopt_cmd(
								t_cmd_config *config,
								int *argc,
								char ***argv,
								t_opt_error *err);

t_cli_parser			*ft_getopt(
								t_cli_config *config,
								int *argc,
								char ***argv,
								t_opt_error *err);

/*
**	Cmd builder functions
*/

t_cmd_builder_parser	*ft_create_cmd_builder_parser(
								int *argc,
								char ***argv,
								char *helper);
void					ft_free_cmd_builder_parser(t_cmd_builder_parser **pa);

t_cmd_builder_parser_n	*ft_create_cmd_builder_parser_node_cmd(
								char *cmd,
								char *helper);
t_cmd_builder_parser_n	*ft_create_cmd_builder_parser_node_cli(
								char *cmd,
								t_cli_builder_parser **builder_cli);
t_cmd_builder_parser_n	*ft_create_cmd_builder_parser_node_cli_w_help(
								char *cmd,
								char *help,
								t_cli_builder_parser **builder_cli);
t_cmd_builder_parser_n	*ft_create_help_sub_cmd(void);
void					ft_free_cmd_builder_parser_node(
								t_cmd_builder_parser_n *n);

void					ft_add_cmd_u(
							t_cmd_builder_parser *p,
							t_cmd_builder_parser_n *n);

void					ft_add_cmd(
							t_cmd_builder_parser *p,
							t_cmd_builder_parser_n **n);

void					ft_add_sub_cmd_u(
							t_cmd_builder_parser_n *p,
							t_cmd_builder_parser_n *n);

void					ft_add_sub_cmd(
							t_cmd_builder_parser_n *p,
							t_cmd_builder_parser_n **n);

/*
**	Cmd functions
*/

t_cmd_parser			*ft_run_cmd(
							t_cmd_builder_parser **builder,
							t_opt_error *opt);

void					ft_free_cmd_parser(t_cmd_parser **pa);

/*
**	Cli builder functions
**		- base : ft_create_cli_builder
**		- create_opt (e.g) : ft_create_l_opt
**		- create_arg (e.g) : ft_create_bool_arg
**		- ft_cli_add
*/

t_cli_builder_parser	*ft_create_cli_builder(
								char *helper);
t_cli_builder_parser	*ft_copy_cli_builder(
								t_cli_builder_parser *p,
								char *help);
void					ft_free_cli_builder(
								t_cli_builder_parser *parser);

t_cli_opt				*ft_create_s_opt(char c, char *help);
t_cli_opt				*ft_create_l_opt(char *s, char *help);
t_cli_opt				*ft_create_sl_opt(char c, char *s, char *help);

t_cli_arg				*ft_create_bool_arg(char *target, t_bool def);
t_cli_arg				*ft_create_string_arg(char *target, char *def);
t_cli_arg				*ft_create_array_arg(char *target);

void					ft_cli_add_u(
								t_cli_builder_parser *builder,
								t_cli_opt *opt,
								t_cli_arg *arg);

void					ft_cli_add(
								t_cli_builder_parser *builder,
								t_cli_opt **opt_ptr,
								t_cli_arg **arg_ptr);

/*
**	Cli functions
**		- ft_run_cli
**		- ft_free_cli_parser
**		- getter (e.g) : ft_cli_getb
**		- ft_cli_getstr_rc
*/

t_cli_parser			*ft_run_cli_u(
								t_cli_builder_parser *builder,
								int argc,
								char **argv,
								t_opt_error *error);

t_cli_parser			*ft_run_cli(
								t_cli_builder_parser **builder,
								int *argc,
								char ***argv,
								t_opt_error *error);

void					ft_free_cli_parser(t_cli_parser **parser);

t_bool					ft_cli_getb(t_cli_parser *parser, char *target);
char					*ft_cli_gets(t_cli_parser *parser, char *target);
char					**ft_cli_geta(t_cli_parser *parser, char *target);

char					*ft_cli_getstr_rc(t_opt_error err);

#endif
