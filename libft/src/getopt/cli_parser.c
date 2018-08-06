/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:33:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 10:28:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_parser	*ft_create_cli_parser()
{
	t_cli_parser	*res;

	ft_memcheck((res = (t_cli_parser *)malloc(sizeof(t_cli_parser))));
	res->short_opts = ft_llist_new(ft_free_opt_s_cli, NULL);
	res->long_opts = ft_llist_new(ft_free_opt_l_cli, NULL);
	res->args = ft_llist_new(ft_free_cli_arg, NULL);
	return res;
}

void			ft_free_cli_parser(t_cli_parser *parser)
{
	if (parser == NULL)
		return ;
	ft_llist_free(&(parser->short_opts));
	ft_llist_free(&(parser->long_opts));
	ft_llist_free(&(parser->args));
	free(parser);
}
