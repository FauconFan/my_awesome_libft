/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 10:28:09 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 20:32:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_add_s_opt(t_cli_parser *parser, char c, t_cli_arg *arg)
{
	t_cli_opt	*opt;
	char		*target;

	target = ft_cli_get_target(arg);
	opt = ft_create_short_opt_cli(c, target);
	if (ft_cli_is_bool(arg))
	{
		ft_llist_addfront(parser->bool_opts, opt);
	}
	else
	{
		ft_llist_addfront(parser->string_opts, opt);
	}
	ft_llist_addfront(parser->args, arg);
}

void		ft_add_l_opt(t_cli_parser *parser, char *s, t_cli_arg *arg)
{
	t_cli_opt	*opt;
	char		*target;

	target = ft_cli_get_target(arg);
	opt = ft_create_long_opt_cli(s, target);
	if (ft_cli_is_bool(arg))
	{
		ft_llist_addfront(parser->bool_opts, opt);
	}
	else
	{
		ft_llist_addfront(parser->string_opts, opt);
	}
	ft_llist_addfront(parser->args, arg);
}

void		ft_add_sl_opt(t_cli_parser *parser, char c, char *s, t_cli_arg *arg)
{
	t_cli_opt	*opt_s;
	t_cli_opt	*opt_l;
	char		*target;

	target = ft_cli_get_target(arg);
	opt_s = ft_create_short_opt_cli(c, target);
	opt_l = ft_create_long_opt_cli(s, target);
	if (ft_cli_is_bool(arg))
	{
		ft_llist_addfront(parser->bool_opts, opt_s);
		ft_llist_addfront(parser->bool_opts, opt_l);
	}
	else
	{
		ft_llist_addfront(parser->string_opts, opt_s);
		ft_llist_addfront(parser->string_opts, opt_l);
	}
	ft_llist_addfront(parser->args, arg);
}
