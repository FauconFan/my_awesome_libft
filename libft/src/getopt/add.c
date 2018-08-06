/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 10:28:09 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 15:29:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_add_s_opt(
					t_cli_builder_parser *parser,
					char c,
					t_cli_arg *arg)
{
	t_cli_s_opt		*opt;
	char			*target;

	target = ft_cli_get_target(arg);
	opt = ft_create_short_opt_cli(c, target);
	ft_llist_addfront(parser->short_opts, opt);
	ft_llist_addfront(parser->args, arg);
}

static void		ft_add_l_opt(
					t_cli_builder_parser *parser,
					char *s,
					t_cli_arg *arg)
{
	t_cli_l_opt		*opt;
	char			*target;

	target = ft_cli_get_target(arg);
	opt = ft_create_long_opt_cli(s, target);
	ft_llist_addfront(parser->long_opts, opt);
	ft_llist_addfront(parser->args, arg);
}

static void		ft_add_sl_opt(
					t_cli_builder_parser *parser,
					char c,
					char *s,
					t_cli_arg *arg)
{
	t_cli_s_opt		*opt_s;
	t_cli_l_opt		*opt_l;
	char			*target;

	target = ft_cli_get_target(arg);
	opt_s = ft_create_short_opt_cli(c, target);
	opt_l = ft_create_long_opt_cli(s, target);
	ft_llist_addfront(parser->short_opts, opt_s);
	ft_llist_addfront(parser->long_opts, opt_l);
	ft_llist_addfront(parser->args, arg);
}

void		ft_cli_add(
					t_cli_builder_parser *builder,
					t_cli_opt **opt_ptr,
					t_cli_arg **arg_ptr)
{
	t_cli_opt	*opt;
	t_cli_arg	*arg;

	opt = *opt_ptr;
	arg = *arg_ptr;
	if (opt->short_opt != NULL && opt->long_opt != NULL)
	{
		ft_add_sl_opt(builder, *(opt->short_opt), opt->long_opt, arg);
	}
	else if (opt->short_opt != NULL)
	{
		ft_add_s_opt(builder, *(opt->short_opt), arg);
	}
	else if (opt->long_opt != NULL)
	{
		ft_add_l_opt(builder, opt->long_opt, arg);
	}
	ft_free_cli_opt(opt_ptr);
	*arg_ptr = NULL;
}
