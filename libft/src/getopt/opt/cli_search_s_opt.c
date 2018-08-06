/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_search_s_opt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:34:06 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 13:58:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *short_cli_void, void *c_void, void *res_void)
{
	t_cli_s_opt	*opt;
	char		c;
	char		**res;

	opt = (t_cli_s_opt *)short_cli_void;
	c = *((char *)c_void);
	res = (char **)res_void;
	if (c == opt->opt)
	{
		*res = opt->target;
	}
}

char			*ft_search_target_s_opt(t_cli_builder_parser *parser, char c)
{
	char	*res;

	res = NULL;
	ft_llist_iterparam2(parser->short_opts, &c, &res, f);
	return res;
}
