/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 10:28:09 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 10:43:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_add_s_opt(t_cli_parser *parser, char c, t_cli_arg *arg)
{
	t_cli_opt	*opt;

	opt = ft_create_short_opt_cli(c, arg->target);
	if (arg->id_action == STORE_TRUE || arg->id_action == STORE_FALSE)
	{
		ft_llist_addfront(parser->bool_opts, opt);
	}
	else
	{
		ft_llist_addfront(parser->string_opts, opt);
	}
	ft_llist_addfront(parser->args, arg);
}
