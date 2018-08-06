/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 18:42:27 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 15:32:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_parser	*ft_run_cli(
							t_cli_builder_parser **builder,
							int argc,
							char **argv,
							t_opt_error *error)
{
	t_cli_parser	*res_parser;

	if (builder == NULL || *builder == NULL || argv == NULL || error == NULL)
	{
		if (error)
			*error = NOT_USED_WELL;
		return NULL;
	}
	ft_memcheck(
		(res_parser = (t_cli_parser *)malloc(sizeof(t_cli_parser))));
	res_parser->argc = argc;
	res_parser->argv = argv;
	res_parser->list_bool = NULL;
	res_parser->list_string = NULL;
	res_parser->list_array = NULL;
	*error = ft_cli_parse(res_parser, *builder);
	if (*error == OK)
	{
		res_parser->list_bool = ft_llist_new(ft_free_res_bool, NULL);
		res_parser->list_string = ft_llist_new(ft_free_res_string, NULL);
		res_parser->list_array = ft_llist_new(ft_free_res_array, NULL);
		ft_finish_res_cli_parser(res_parser, *builder);
	}
	ft_free_cli_builder(*builder);
	*builder = NULL;
	return res_parser;
}

void			ft_free_cli_parser(t_cli_parser *parser)
{
	if (parser == NULL)
		return ;
	ft_llist_free(&(parser->list_bool));
	ft_llist_free(&(parser->list_string));
	ft_llist_free(&(parser->list_array));
	free(parser);
}
