/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_search_l_opt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:34:06 by jpriou            #+#    #+#             */
/*   Updated: 2018/10/04 15:31:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *long_cli_void, void *s_void, void *res_void)
{
	t_cli_l_opt	*opt;
	char		*s;
	char		**res;

	opt = (t_cli_l_opt *)long_cli_void;
	s = (char *)s_void;
	res = (char **)res_void;
	if (ft_strcmp(s, opt->opt) == 0)
	{
		*res = opt->target;
	}
}

char			*ft_search_target_l_opt(t_cli_builder_parser *parser, char *s)
{
	char	*res;

	res = NULL;
	ft_slist_iterparam2(parser->long_opts, s, &res, f);
	return (res);
}
