/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_builder_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:33:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 17:54:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_builder_parser	*ft_create_cli_builder(char *helper)
{
	t_cli_builder_parser	*res;

	ft_memcheck(
		(res = (t_cli_builder_parser *)malloc(sizeof(t_cli_builder_parser))));
	res->helper = ft_strdup(helper);
	res->short_opts = ft_slist_new(MAKE_FREE_PTR(ft_free_opt_s_cli));
	res->long_opts = ft_slist_new(MAKE_FREE_PTR(ft_free_opt_l_cli));
	res->args = ft_slist_new(MAKE_FREE_PTR(ft_free_cli_arg));
	res->helps = ft_slist_new(MAKE_FREE_PTR(ft_free_cli_opt));
	ft_slist_add_cpy(res->short_opts, MAKE_COPY_PTR(ft_copy_short_opt_cli));
	ft_slist_add_cpy(res->long_opts, MAKE_COPY_PTR(ft_copy_long_opt_cli));
	ft_slist_add_cpy(res->args, MAKE_COPY_PTR(ft_copy_cli_arg));
	ft_slist_add_cpy(res->helps, MAKE_COPY_PTR(ft_copy_cli_opt));
	return (res);
}

t_cli_builder_parser	*ft_copy_cli_builder(
								t_cli_builder_parser *p,
								char *helper)
{
	t_cli_builder_parser	*res;

	ft_memcheck(
		(res = (t_cli_builder_parser *)malloc(sizeof(t_cli_builder_parser))));
	res->short_opts = ft_slist_cpy(p->short_opts);
	res->long_opts = ft_slist_cpy(p->long_opts);
	res->args = ft_slist_cpy(p->args);
	res->helper = ft_strdup(helper);
	res->helps = ft_slist_cpy(p->helps);
	return (res);
}

void					ft_free_cli_builder(t_cli_builder_parser *parser)
{
	if (parser == NULL)
		return ;
	ft_slist_free(&(parser->short_opts));
	ft_slist_free(&(parser->long_opts));
	ft_slist_free(&(parser->args));
	ft_strdel(&(parser->helper));
	ft_slist_free(&(parser->helps));
	free(parser);
}
