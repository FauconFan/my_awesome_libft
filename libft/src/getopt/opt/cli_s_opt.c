/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_s_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 09:39:06 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/06 10:26:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_s_opt		*ft_create_short_opt_cli(char c, char *target)
{
	t_cli_s_opt	*res;

	ft_memcheck((res = (t_cli_s_opt *)malloc(sizeof(t_cli_s_opt))));
	res->opt = c;
	res->target = ft_strdup(target);
	return res;
}

void			ft_free_opt_s_cli(void *opt_void)
{
	t_cli_s_opt	*opt;

	opt = (t_cli_s_opt *)opt_void;
	if (opt == NULL)
		return ;
	free(opt->target);
	free(opt);
}
