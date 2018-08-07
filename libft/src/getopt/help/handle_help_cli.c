/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_help_cli.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 17:10:20 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/07 14:24:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		display_f(void *elem)
{
	t_cli_opt	*opt;
	char		*delim;
	char		*sh;
	char		*lo;

	opt = (t_cli_opt *)elem;
	delim = (opt->short_opt && opt->long_opt) ? ", " : "  ";
	if (opt->short_opt)
		ft_sprintf(&sh, "-%c", *(opt->short_opt));
	else
		sh = ft_strsetnew(2, ' ');
	if (opt->long_opt && opt->type)
		ft_sprintf(&lo, "--%s %s", opt->long_opt, opt->type);
	else if (opt->long_opt == NULL && opt->type == NULL)
		lo = ft_strnew(0);
	else if (opt->long_opt)
		ft_sprintf(&lo, "--%s", opt->long_opt);
	else
		lo = ft_strdup(opt->type);
	ft_printf("  %s%s%-34s", sh, delim, lo);
	if (opt->help)
		ft_putstr(opt->help);
	ft_putchar('\n');
	ft_strdel(&sh);
	ft_strdel(&lo);
}

static int		cmp_f(void *d1, void *d2)
{
	t_cli_opt	*opt1;
	t_cli_opt	*opt2;

	opt1 = (t_cli_opt *)d1;
	opt2 = (t_cli_opt *)d2;
	if (opt1->long_opt != NULL && opt2->long_opt != NULL)
	{
		return ft_strcmp(opt1->long_opt, opt2->long_opt);
	}
	else if (opt1->long_opt != NULL)
	{
		if (*(opt1->long_opt) == *(opt2->short_opt))
			return (1);
		return (*(opt1->long_opt) - *(opt2->short_opt));
	}
	else if (opt2->long_opt != NULL)
	{
		if (*(opt1->short_opt) == *(opt2->long_opt))
			return (-1);
		return (*(opt1->short_opt) - *(opt2->long_opt));
	}
	return (*(opt1->short_opt) - *(opt2->short_opt));
}

void			handle_help_cli(t_cli_builder_parser *builder, t_opt_error *err)
{
	ft_llist_sort(&(builder->helps), cmp_f);
	ft_printf("Usage: %s [OPTIONS...] [ARGS...]\n\n", builder->argv0);
	ft_printf("%s\n\n", builder->helper);
	if (err != NULL && is_user_fault(*err))
		ft_printf("%s\n\n", ft_cli_getstr_rc(*err));
	ft_putendl("Options:");
	ft_llist_iter(builder->helps, display_f);
}
