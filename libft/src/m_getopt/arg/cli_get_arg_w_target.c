/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_get_arg_w_target.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:51:15 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/09 16:40:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool			is_target(void *elem, void *param)
{
	t_cli_arg		*arg;
	char			*target;
	t_res_bool		*bo;
	t_res_string	*st;
	t_res_array		*ar;

	arg = (t_cli_arg *)elem;
	target = (char *)param;
	if (ft_cli_is_bool(arg))
	{
		bo = (t_res_bool *)arg->content;
		return (ft_strcmp(bo->target, target) == 0);
	}
	else if (ft_cli_is_string(arg))
	{
		st = (t_res_string *)arg->content;
		return (ft_strcmp(st->target, target) == 0);
	}
	else if (ft_cli_is_array(arg))
	{
		ar = (t_res_array *)arg->content;
		return (ft_strcmp(ar->target, target) == 0);
	}
	return (FALSE);
}

t_cli_arg				*get_arg_w_target(t_cli_builder_parser *parser, char *target)
{
	return (ft_slist_findparam(parser->args, NULL, target, is_target));
}
