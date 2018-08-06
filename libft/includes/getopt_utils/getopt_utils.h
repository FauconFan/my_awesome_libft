/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:19:05 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 11:32:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETOPT_UTILS_H
#define GETOPT_UTILS_H

/*
**	Options typdefs
*/

typedef struct		s_cli_s_opt
{
	char			opt;
	char			*target;
}					t_cli_s_opt;

typedef struct		s_cli_l_opt
{
	char			*opt;
	char			*target;
}					t_cli_l_opt;

/*
**	Arguments typdefs
*/

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
	void			*content;
}					t_cli_arg;

/*
**	Res cli typdefs
*/

typedef struct		s_res_bool
{
	char			*target;
	t_bool			value;
}					t_res_bool;

typedef struct		s_res_string
{
	char			*target;
	char			*value;
}					t_res_string;

typedef struct		s_res_array
{
	char			*target;
	char			**value;
}					t_res_array;

/*
**	Functions Opt
*/

t_cli_s_opt			*ft_create_short_opt_cli(char c, char *target);
void				ft_free_opt_s_cli(void *opt);

char				*ft_search_target_s_opt(t_cli_parser *parser, char c);

t_cli_l_opt			*ft_create_long_opt_cli(char *s, char *target);
void				ft_free_opt_l_cli(void *opt_void);

char				*ft_search_target_l_opt(t_cli_parser *parser, char *s);

/*
**	Functions Arg
*/

t_cli_arg			*ft_create_bool_arg(char *target, t_bool def);
t_cli_arg			*ft_create_string_arg(char *target, char *def);
t_cli_arg			*ft_create_array_arg(char *target);
void				ft_free_cli_arg(void *arg);

t_cli_arg			*get_arg_w_target(t_cli_parser *parser, char *target);

/*
**	Functions res_bool
*/

t_res_bool			*ft_create_res_bool(char *target, t_bool value);
void				*ft_copy_res_bool(void *v);
void				ft_free_res_bool(void *v);

/*
**	Functions res_string
*/

t_res_string		*ft_create_res_string(char *target, char *def);
void				*ft_copy_res_string(void *v);
void				ft_free_res_string(void *v);
void				ft_res_string_replace(t_res_string *r, char *s);

/*
**	Functions res_array
*/


t_res_array			*ft_create_res_array(char *target);
void				*ft_copy_res_array(void *v);
void				ft_free_res_array(void *v);
void				ft_cli_array_append(t_res_array *a, char *s);

/*
**	Functions parsing
*/

void				ft_finish_res_cli_parser(
							t_res_cli_parser *res_parser,
							t_cli_parser *parser);

t_opt_error			ft_cli_parse(
							t_res_cli_parser *res_parser,
							t_cli_parser *parser);

t_opt_error			ft_treat_arg(
							t_res_cli_parser *res_parser,
							t_cli_arg *arg,
							t_bool allow_next);

/*
**	Functions Utils
*/

char				*ft_cli_get_target(t_cli_arg *arg);
t_bool				ft_cli_is_bool(t_cli_arg *arg);
t_bool				ft_cli_is_string(t_cli_arg *arg);
t_bool				ft_cli_is_array(t_cli_arg *arg);

#endif
