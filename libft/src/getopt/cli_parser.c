/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:33:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 19:50:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_parser	*ft_create_cli_parser()
{
	t_cli_parser	*res;

	ft_memcheck((res = (t_cli_parser *)malloc(sizeof(t_cli_parser))));
	res->bool_opts = ft_llist_new(ft_free_opt_cli, NULL);
	res->string_opts = ft_llist_new(ft_free_opt_cli, NULL);
	res->args = ft_llist_new(ft_free_cli_arg, NULL);
	return res;
}

void			ft_free_cli_parser(t_cli_parser *parser)
{
	if (parser == NULL)
		return ;
	ft_llist_free(&(parser->bool_opts));
	ft_llist_free(&(parser->string_opts));
	ft_llist_free(&(parser->args));
	free(parser);
}
