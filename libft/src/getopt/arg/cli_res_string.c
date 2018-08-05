/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_res_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:54:57 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 20:12:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_res_string	*ft_create_res_string(char *target, char *def)
{
	t_res_string	*res;

	ft_memcheck((res = (t_res_string *)malloc(sizeof(t_res_string))));
	res->target = ft_strdup(target);
	if (def == NULL)
		res->value = NULL;
	else
		res->value = ft_strdup(def);
	return res;
}

void			*ft_copy_res_string(void *v)
{
	t_res_string	*actu;

	actu = (t_res_string *)v;
	return ft_create_res_string(actu->target, actu->value);
}

void			ft_free_res_string(void *v)
{
	t_res_string	*s;

	s = (t_res_string *)v;
	free(s->target);
	if (s->value)
		free(s->value);
	free(s);
}

void			ft_res_string_replace(t_res_string *r, char *s)
{
	if (r->value)
		free(r->value);
	r->value = ft_strdup(s);
}
