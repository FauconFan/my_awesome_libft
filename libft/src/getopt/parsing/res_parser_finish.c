/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_parser_finish.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 19:27:31 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 20:38:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		apply_arg_in_res_parser(void *arg_void, void *res_parser_void)
{
	t_res_cli_parser	*res_parser;
	t_cli_arg			*arg;
	void				*content_arg;

	res_parser = (t_res_cli_parser *)res_parser_void;
	arg = (t_cli_arg *)arg_void;
	content_arg = arg->content;
	if (ft_cli_is_bool(arg))
	{
		ft_llist_addfront(res_parser->list_bool, ft_copy_res_bool(content_arg));
	}
	else if (ft_cli_is_string(arg))
	{
		ft_llist_addfront(res_parser->list_string, ft_copy_res_string(content_arg));
	}
	else if (ft_cli_is_array(arg))
	{
		ft_llist_addfront(res_parser->list_array, ft_copy_res_array(content_arg));
	}
}

void			ft_finish_res_cli_parser(
					t_res_cli_parser *res_parser, t_cli_parser *parser)
{
	ft_llist_iterparam(parser->args, res_parser, apply_arg_in_res_parser);
}
