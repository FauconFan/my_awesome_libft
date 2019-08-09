/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:58:13 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/02 15:16:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cli_opt		*ft_create_s_opt(char c, char *help)
{
	t_cli_opt	*res;

	ft_memcheck((res = (t_cli_opt *)malloc(sizeof(t_cli_opt))));
	res->short_opt = ft_strnew(1);
	res->short_opt[0] = c;
	res->long_opt = NULL;
	if (help == NULL)
		res->help = NULL;
	else
		res->help = ft_strdup(help);
	res->type = NULL;
	return (res);
}

t_cli_opt		*ft_create_l_opt(char *s, char *help)
{
	t_cli_opt	*res;

	if (s == NULL)
		return (NULL);
	ft_memcheck((res = (t_cli_opt *)malloc(sizeof(t_cli_opt))));
	res->short_opt = NULL;
	res->long_opt = ft_strdup(s);
	if (help == NULL)
		res->help = NULL;
	else
		res->help = ft_strdup(help);
	res->type = NULL;
	return (res);
}

t_cli_opt		*ft_create_sl_opt(char c, char *s, char *help)
{
	t_cli_opt	*res;

	if (s == NULL)
		return (NULL);
	ft_memcheck((res = (t_cli_opt *)malloc(sizeof(t_cli_opt))));
	res->short_opt = ft_strnew(1);
	res->short_opt[0] = c;
	res->long_opt = ft_strdup(s);
	if (help == NULL)
		res->help = NULL;
	else
		res->help = ft_strdup(help);
	res->type = NULL;
	return (res);
}

t_cli_opt		*ft_copy_cli_opt(t_cli_opt *opt)
{
	t_cli_opt	*res;

	ft_memcheck((res = (t_cli_opt *)malloc(sizeof(t_cli_opt))));
	res->short_opt = (opt->short_opt) ? ft_strdup(opt->short_opt) : NULL;
	res->long_opt = (opt->long_opt) ? ft_strdup(opt->long_opt) : NULL;
	res->help = (opt->help) ? ft_strdup(opt->help) : NULL;
	res->type = (opt->type) ? ft_strdup(opt->type) : NULL;
	return (res);
}

void			ft_free_cli_opt(t_cli_opt *opt)
{
	if (opt->short_opt)
		free(opt->short_opt);
	if (opt->long_opt)
		free(opt->long_opt);
	if (opt->help)
		free(opt->help);
	if (opt->type)
		free(opt->type);
	free(opt);
}
