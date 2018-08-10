/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cli_getb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:47:16 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 14:07:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		f(void *res_bool_void, void *target_void, void *res_void)
{
	t_res_bool	*res_bool;
	t_bool		*bool_ptr;
	char		*target;

	res_bool = (t_res_bool *)res_bool_void;
	bool_ptr = (t_bool *)res_void;
	target = (char *)target_void;
	if (ft_strcmp(res_bool->target, target) == 0)
	{
		*bool_ptr = res_bool->value;
	}
}

t_bool			ft_cli_getb(t_cli_parser *parser, char *target)
{
	t_bool	res;

	res = FALSE;
	ft_slist_iterparam2(parser->list_bool, target, &res, f);
	return res;
}
