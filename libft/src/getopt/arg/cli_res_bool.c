/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_res_bool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:54:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 20:11:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_res_bool		*ft_create_res_bool(char *target, t_bool value)
{
	t_res_bool	*res;

	ft_memcheck((res = (t_res_bool *)malloc(sizeof(t_res_bool))));
	res->target = ft_strdup(target);
	res->value = value;
	return res;
}

void			*ft_copy_res_bool(void *v)
{
	t_res_bool	*actu;

	actu = (t_res_bool *)v;
	return ft_create_res_bool(actu->target, actu->value);
}

void			ft_free_res_bool(void *v)
{
	t_res_bool	*b;

	b = (t_res_bool *)v;
	free(b->target);
	free(b);
}
