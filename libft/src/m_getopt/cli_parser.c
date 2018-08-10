/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 18:42:27 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:07:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_run_cli2(
							t_cli_builder_parser *builder,
							t_cli_parser *parser,
							t_opt_error *error)
{
	t_cli_opt	*opt_help;
	t_cli_arg	*arg_help;
	char		*argv0;

	opt_help = ft_create_sl_opt('h', "help", "Show this message");
	arg_help = ft_create_bool_arg("help_target", FALSE);
	ft_cli_add(builder, &opt_help, &arg_help);
	argv0 = parser->argv[0];
	parser->argv = parser->argv + 1;
	parser->argc = parser->argc - 1;
	*error = ft_cli_parse(parser, builder);
	if (is_user_fault(*error))
		handle_help_cli(argv0, builder, error);
	else if (*error == OK)
	{
		parser->list_bool = ft_slist_new(MAKE_FREE_PTR(ft_free_res_bool));
		parser->list_string = ft_slist_new(MAKE_FREE_PTR(ft_free_res_string));
		parser->list_array = ft_slist_new(MAKE_FREE_PTR(ft_free_res_array));
		ft_finish_res_cli_parser(parser, builder);
	}
	if (*error == OK && ft_cli_getb(parser, "help_target"))
	{
		handle_help_cli(argv0, builder, NULL);
		*error = HELP_CALLED;
	}
}

t_cli_parser	*ft_run_cli_u(
							t_cli_builder_parser *builder,
							int argc,
							char **argv,
							t_opt_error *error)
{
	t_cli_parser	*parser;

	ft_memcheck(
		(parser = (t_cli_parser *)malloc(sizeof(t_cli_parser))));
	parser->argc = argc;
	parser->argv = argv;
	parser->list_bool = NULL;
	parser->list_string = NULL;
	parser->list_array = NULL;
	ft_run_cli2(builder, parser, error);
	return parser;
}

t_cli_parser	*ft_run_cli(
							t_cli_builder_parser **builder,
							int argc,
							char **argv,
							t_opt_error *error)
{
	t_cli_parser	*parser;

	if (builder == NULL || *builder == NULL || argv == NULL || error == NULL)
	{
		if (error)
			*error = NOT_USED_WELL;
		return NULL;
	}
	parser = ft_run_cli_u(*builder, argc, argv, error);
	ft_free_cli_builder(*builder);
	*builder = NULL;
	return parser;
}

void			ft_free_cli_parser(t_cli_parser **parser)
{
	if (parser == NULL || *parser == NULL)
		return ;
	ft_slist_free(&((*parser)->list_bool));
	ft_slist_free(&((*parser)->list_string));
	ft_slist_free(&((*parser)->list_array));
	free(*parser);
	*parser = NULL;
}
