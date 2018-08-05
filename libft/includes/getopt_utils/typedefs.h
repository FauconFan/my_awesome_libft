/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:44:02 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 19:44:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETOPT_TYPEDEFS_H
#define GETOPT_TYPEDEFS_H

typedef struct		s_cli_parser
{
	t_llist			*bool_opts;
	t_llist			*string_opts;
	t_llist			*args;
}					t_cli_parser;

typedef struct		s_res_cli_parser
{
	int				argc;
	char			**argv;
	t_llist			*list_bool;
	t_llist			*list_string;
	t_llist			*list_array;
}					t_res_cli_parser;

typedef enum		e_opt_error
{
	OK,
	NOT_USED_WELL
}					t_opt_error;

#endif
