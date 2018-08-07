/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:56:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 11:29:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_arg		*ft_create_bool_arg(char *target, t_bool def)
{
	t_cli_arg	*res;

	ft_memcheck((res = (t_cli_arg *)malloc(sizeof(t_cli_arg))));
	res->id_action = (def) ? STORE_FALSE : STORE_TRUE;
	res->content = ft_create_res_bool(target, def);
	return res;
}

t_cli_arg		*ft_create_string_arg(char *target, char *def)
{
	t_cli_arg	*res;

	ft_memcheck((res = (t_cli_arg *)malloc(sizeof(t_cli_arg))));
	res->id_action = REPLACE;
	res->content = ft_create_res_string(target, def);
	return res;
}

t_cli_arg		*ft_create_array_arg(char *target)
{
	t_cli_arg	*res;

	ft_memcheck((res = (t_cli_arg *)malloc(sizeof(t_cli_arg))));
	res->id_action = APPEND;
	res->content = ft_create_res_array(target);
	return res;
}

t_cli_arg		*ft_copy_cli_arg(t_cli_arg *arg)
{
	t_cli_arg	*res;

	ft_memcheck((res = (t_cli_arg *)malloc(sizeof(t_cli_arg))));
	res->id_action = arg->id_action;
	if (ft_cli_is_bool(arg))
	{
		res->content = ft_copy_res_bool(arg->content);
	}
	if (ft_cli_is_string(arg))
	{
		res->content = ft_copy_res_string(arg->content);
	}
	if (ft_cli_is_array(arg))
	{
		res->content = ft_copy_res_array(arg->content);
	}
	return res;
}

void			ft_free_cli_arg(void *arg_void)
{
	t_cli_arg	*arg;

	arg = (t_cli_arg *)arg_void;
	if (arg == NULL)
		return ;
	if (ft_cli_is_bool(arg))
	{
		ft_free_res_bool(arg->content);
	}
	else if (ft_cli_is_string(arg))
	{
		ft_free_res_string(arg->content);
	}
	else if (ft_cli_is_array(arg))
	{
		ft_free_res_array(arg->content);
	}
	free(arg);
}
