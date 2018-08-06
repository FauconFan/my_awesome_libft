/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:04:34 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 11:52:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_OPT_H
#define GET_OPT_H

#include "libft.h"
#include "includes/libft_linked_list.h"
#include "includes/libft_tab.h"
#include "includes/getopt_utils/typedefs.h"
#include "includes/getopt_utils/getopt_utils.h"

t_cli_parser		*ft_create_cli_parser();
void				ft_free_cli_parser(t_cli_parser *parser);

void				ft_add_s_opt(
							t_cli_parser *parser,
							char c,
							t_cli_arg *arg);
void				ft_add_l_opt(
							t_cli_parser *parser,
							char *s,
							t_cli_arg *arg);
void				ft_add_sl_opt(
							t_cli_parser *parser,
							char c,
							char *s,
							t_cli_arg *arg);

t_res_cli_parser	*ft_create_res_cli_parser(
							t_cli_parser *parser,
							int argc,
							char **argv,
							t_opt_error *error);

void				ft_free_res_cli_parser(t_res_cli_parser *parser);

t_bool				ft_cli_getb(t_res_cli_parser *parser, char *target);
char				*ft_cli_gets(t_res_cli_parser *parser, char *target);
char				**ft_cli_geta(t_res_cli_parser *parser, char *target);

char				*ft_cli_getstr_rc(t_opt_error err);

#endif
