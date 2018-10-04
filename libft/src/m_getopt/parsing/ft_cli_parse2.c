/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cli_parse2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:12:22 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 15:32:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		handle_next_arg(
					t_cli_parser *res_parser,
					t_cli_arg *arg)
{
	char			*next_arg;
	t_res_string	*st;
	t_res_array		*ar;

	res_parser->argc = res_parser->argc - 1;
	res_parser->argv = res_parser->argv + 1;
	next_arg = *(res_parser->argv);
	if (ft_cli_is_string(arg))
	{
		st = (t_res_string *)arg->content;
		ft_res_string_replace(st, next_arg);
	}
	else if (ft_cli_is_array(arg))
	{
		ar = (t_res_array *)arg->content;
		ft_cli_array_append(ar, next_arg);
	}
}

t_opt_error		ft_treat_arg(
					t_cli_parser *res_parser,
					t_cli_arg *arg,
					t_bool allow_next)
{
	t_res_bool	*bo;

	(void)res_parser;
	if (ft_cli_is_bool(arg))
	{
		bo = (t_res_bool *)arg->content;
		if (arg->id_action == STORE_TRUE)
			bo->value = TRUE;
		else
			bo->value = FALSE;
	}
	else
	{
		if (allow_next == FALSE)
			return (NO_NEXT_ARGUMENT_ALLOWED);
		else if (res_parser->argc <= 1)
			return (NO_NEXT_ARGUMENT_GIVEN);
		handle_next_arg(res_parser, arg);
	}
	return (OK);
}
