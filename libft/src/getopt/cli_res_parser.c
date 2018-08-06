/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_res_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 18:42:27 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 11:06:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_res_cli_parser	*ft_create_res_cli_parser(
							t_cli_parser *parser,
							int argc,
							char **argv,
							t_opt_error *error)
{
	t_res_cli_parser	*res_parser;

	if (parser == NULL || argv == NULL || error == NULL)
	{
		if (error)
			*error = NOT_USED_WELL;
		return NULL;
	}
	ft_memcheck(
		(res_parser = (t_res_cli_parser *)malloc(sizeof(t_res_cli_parser))));
	res_parser->argc = argc;
	res_parser->argv = argv;
	res_parser->list_bool = NULL;
	res_parser->list_string = NULL;
	res_parser->list_array = NULL;
	*error = ft_cli_parse(res_parser, parser);
	if (*error == OK)
	{
		res_parser->list_bool = ft_llist_new(ft_free_res_bool, NULL);
		res_parser->list_string = ft_llist_new(ft_free_res_string, NULL);
		res_parser->list_array = ft_llist_new(ft_free_res_array, NULL);
		ft_finish_res_cli_parser(res_parser, parser);
	}
	return res_parser;
}

void				ft_free_res_cli_parser(t_res_cli_parser *parser)
{
	if (parser == NULL)
		return ;
	ft_llist_free(&(parser->list_bool));
	ft_llist_free(&(parser->list_string));
	ft_llist_free(&(parser->list_array));
	free(parser);
}
