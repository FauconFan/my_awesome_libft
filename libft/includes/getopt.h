/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:04:34 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 20:46:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_OPT_H
#define GET_OPT_H

#include "libft.h"
#include "includes/libft_linked_list.h"
#include "includes/libft_tab.h"
#include "includes/getopt_utils/typedefs.h"
#include "includes/getopt_utils/getopt_utils.h"

/*
**	Cli builder functions
**		- base : ft_create_cli_builder
**		- create_opt (e.g) : ft_create_l_opt
**		- create_arg (e.g) : ft_create_bool_arg
**		- ft_cli_add
*/

t_cli_builder_parser	*ft_create_cli_builder(char *helper);
void					ft_free_cli_builder(
								t_cli_builder_parser *parser);

t_cli_opt				*ft_create_s_opt(char c, char *help);
t_cli_opt				*ft_create_l_opt(char *s, char *help);
t_cli_opt				*ft_create_sl_opt(char c, char *s, char *help);

t_cli_arg				*ft_create_bool_arg(char *target, t_bool def);
t_cli_arg				*ft_create_string_arg(char *target, char *def);
t_cli_arg				*ft_create_array_arg(char *target);

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

t_cli_parser			*ft_run_cli(
								t_cli_builder_parser **parser,
								int argc,
								char **argv,
								t_opt_error *error);

void					ft_free_cli_parser(t_cli_parser *parser);

t_bool					ft_cli_getb(t_cli_parser *parser, char *target);
char					*ft_cli_gets(t_cli_parser *parser, char *target);
char					**ft_cli_geta(t_cli_parser *parser, char *target);

char					*ft_cli_getstr_rc(t_opt_error err);

#endif
