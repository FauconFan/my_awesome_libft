/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_res_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:54:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 20:21:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_res_array		*ft_create_res_array(char *target)
{
	t_res_array		*res;

	ft_memcheck((res = (t_res_array *)malloc(sizeof(t_res_array))));
	res->target = ft_strdup(target);
	res->value = ft_stab_new(0, NULL);
	return res;
}

void			*ft_copy_res_array(void *v)
{
	t_res_array		*actu;
	t_res_array		*res;
	size_t			i;

	actu = (t_res_array *)v;
	res = ft_create_res_array(actu->target);
	i = 0;
	while (actu->value[i])
	{
		ft_stab_append(&(res->value), actu->value[i]);
		i++;
	}
	return res;
}

void			ft_free_res_array(void *v)
{
	t_res_array		*a;

	a = (t_res_array *)v;
	free(a->target);
	ft_stab_free(&(a->value));
	free(a);
}

void			ft_cli_array_append(t_res_array *a, char *s)
{
	ft_stab_append(&(a->value), s);
}
