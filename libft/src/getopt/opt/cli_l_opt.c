/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_l_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:39:06 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 14:47:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_l_opt		*ft_create_long_opt_cli(char *s, char *target)
{
	t_cli_l_opt	*res;

	ft_memcheck((res = (t_cli_l_opt *)malloc(sizeof(t_cli_l_opt))));
	res->opt = ft_strdup(s);
	res->target = ft_strdup(target);
	return res;
}

void			ft_free_opt_l_cli(void *opt_void)
{
	t_cli_l_opt	*opt;

	opt = (t_cli_l_opt *)opt_void;
	if (opt == NULL)
		return ;
	free(opt->opt);
	free(opt->target);
	free(opt);
}
