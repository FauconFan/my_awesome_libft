/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:56:45 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 10:48:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_arg		*ft_create_bool_arg(char *target, t_bool def)
{
	t_cli_arg	*res;
	t_bool		*ptr;

	ft_memcheck((res = (t_cli_arg *)malloc(sizeof(t_cli_arg))));
	res->id_action = (def) ? STORE_FALSE : STORE_TRUE;
	res->target = ft_strdup(target);
	ft_memcheck((ptr = (t_bool *)malloc(sizeof(t_bool))));
	*ptr = def;
	res->value = (void *)ptr;
	return res;
}

t_cli_arg		*ft_create_string_arg(char *target, char *def)
{
	t_cli_arg	*res;

	ft_memcheck((res = (t_cli_arg *)malloc(sizeof(t_cli_arg))));
	res->id_action = REPLACE;
	res->target = ft_strdup(target);
	res->value = (char *)ft_strdup(def);
	return res;
}

t_cli_arg		*ft_create_array_arg(char *target)
{
	t_cli_arg	*res;

	ft_memcheck((res = (t_cli_arg *)malloc(sizeof(t_cli_arg))));
	res->id_action = APPEND;
	res->target = ft_strdup(target);
	res->value = (void *)ft_stab_new(0, NULL);
	return res;
}

void			ft_free_cli_arg(t_cli_arg *arg)
{
	char	**tab;

	if (arg == NULL)
		return ;
	free(arg->target);
	if (arg->id_action == APPEND)
	{
		tab = (char **)arg->value;
		ft_stab_free(&tab);
	}
	else
	{
		free(arg->value);
	}
	free(arg);
}
