/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cli_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:51:18 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 11:37:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_opt_error 		handling_long_options(
							t_res_cli_parser *res_parser,
							t_cli_parser *parser)
{
	char		*ptr;
	char		*target;
	t_cli_arg	*arg;

	ptr = res_parser->argv[0] + 2;
	target = ft_search_target_l_opt(parser, ptr);
	if (target == NULL)
		return UNKNOWN_OPTION;
	arg = get_arg_w_target(parser, target);
	if (arg == NULL)
		return INTERNAL_ERROR;
	return ft_treat_arg(res_parser, arg, TRUE);
}

static t_opt_error		handling_short_options(
							t_res_cli_parser *res_parser,
							t_cli_parser *parser)
{
	char		*ptr;
	char		*target;
	t_cli_arg	*arg;
	t_opt_error	error;

	ptr = res_parser->argv[0] + 1;
	if (*ptr == '\0')
	{
		return DASH_EMPTY;
	}
	while (*ptr)
	{
		target = ft_search_target_s_opt(parser, *ptr);
		if (target == NULL)
			return UNKNOWN_OPTION;
		arg = get_arg_w_target(parser, target);
		if (arg == NULL)
			return INTERNAL_ERROR;
		error = ft_treat_arg(res_parser, arg, ptr[1] == '\0');
		if (error != OK)
			return error;
		ptr++;
	}
	return OK;
}

t_opt_error				ft_cli_parse(
							t_res_cli_parser *res_parser,
							t_cli_parser *parser)
{
	t_opt_error		actu;

	while (res_parser->argc)
	{
		if (**(res_parser->argv) != '-')
			return OK;
		if (res_parser->argv[0][1] != '-')
			actu = handling_short_options(res_parser, parser);
		else
			actu = handling_long_options(res_parser, parser);
		if (actu != OK)
			return actu;
		res_parser->argv = res_parser->argv + 1;
		res_parser->argc = res_parser->argc - 1;
	}
	return OK;
}
