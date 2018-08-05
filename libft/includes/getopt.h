/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:04:34 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 10:47:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_OPT_H
#define GET_OPT_H

#include "libft.h"
#include "includes/libft_linked_list.h"

typedef enum		e_id_opt
{
	SHORT,
	LONG
}					t_id_opt;

typedef struct		s_cli_opt
{
	t_id_opt		id_opt;
	char			*opt;
	char			*target;
}					t_cli_opt;

typedef enum		e_id_action
{
	STORE_TRUE,
	STORE_FALSE,
	REPLACE,
	APPEND
}					t_id_action;

typedef struct		s_cli_arg
{
	t_id_action		id_action;
	char			*target;
	void			*value;
}					t_cli_arg;

typedef struct		s_cli_parser
{
	t_llist			*bool_opts;
	t_llist			*string_opts;
	t_llist			*args;
}					t_cli_parser;

t_cli_parser		*ft_create_cli_parser();
void				ft_free_cli_parser(t_cli_parser *parser);

t_cli_opt			*ft_create_short_opt_cli(char c, char *target);
t_cli_opt			*ft_create_long_opt_cli(char *s, char *target);
void				ft_free_opt_cli(t_cli_opt *opt);

t_cli_arg			*ft_create_bool_arg(char *target, t_bool def);
t_cli_arg			*ft_create_string_arg(char *target, char *def);
t_cli_arg			*ft_create_array_arg(char *target);
void				ft_free_cli_arg(t_cli_arg *arg);

void				ft_add_s_opt(t_cli_parser *parser, char c, t_cli_arg *arg);

#endif
