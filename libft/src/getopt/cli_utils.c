/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:34:46 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 18:31:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool				ft_cli_is_bool(t_cli_arg *arg)
{
	return (arg->id_action == STORE_TRUE || arg->id_action == STORE_FALSE);
}

t_bool				ft_cli_is_string(t_cli_arg *arg)
{
	return (arg->id_action == REPLACE);
}

t_bool				ft_cli_is_array(t_cli_arg *arg)
{
	return (arg->id_action == APPEND);
}

char				*ft_cli_get_target(t_cli_arg *arg)
{
	t_res_bool		*bo;
	t_res_string	*st;
	t_res_array		*ar;

	if (ft_cli_is_bool(arg))
	{
		bo = (t_res_bool *)arg->content;
		return bo->target;
	}
	else if (ft_cli_is_string(arg))
	{
		st = (t_res_string *)arg->content;
		return st->target;
	}
	else if (ft_cli_is_array(arg))
	{
		ar = (t_res_array *)arg->content;
		return ar->target;
	}
	return NULL;
}
