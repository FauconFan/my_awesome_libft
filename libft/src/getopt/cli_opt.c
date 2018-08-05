/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:39:06 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/05 10:37:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_opt	*ft_create_short_opt_cli(char c, char *target)
{
	t_cli_opt	*res;

	ft_memcheck((res = (t_cli_opt *)malloc(sizeof(t_cli_opt))));
	res->id_opt = SHORT;
	res->opt = ft_strnew(1);
	res->opt[0] = c;
	res->target = ft_strdup(target);
	return res;
}

t_cli_opt	*ft_create_long_opt_cli(char *s, char *target)
{
	t_cli_opt	*res;

	ft_memcheck((res = (t_cli_opt *)malloc(sizeof(t_cli_opt))));
	res->id_opt = LONG;
	res->opt = ft_strdup(s);
	res->target = ft_strdup(target);
	return res;
}

void		ft_free_opt_cli(t_cli_opt *opt)
{
	if (opt == NULL)
		return ;
	free(opt->opt);
	free(opt->target);
	free(opt);
}
